#include <list>
#include <string>

#include "naive-compiler.h"

using namespace CUA;

InstrumentList
NaiveCompiler::compile(ASTNode *root)
{
    root->accept(this);
    ins_list.last_result = result_name;
    return ins_list;
}

void
NaiveCompiler::visit(ASTChunk *n)
{ n->root->accept(this); }

void
NaiveCompiler::visit(ASTStatList *n)
{
    for (std::list<ASTNode *>::iterator it = n->list.begin(); it != n->list.end(); ++it)
    {
		ASTNode *nn = *it;
        nn->accept(this);
    }
}

void
NaiveCompiler::visit(ASTAssignment *n)
{
    std::list<std::string> temp_list;
    
    if (n->expr_list) {
		std::list<ASTNode *>& list = dynamic_cast<ASTExprList*>(n->expr_list)->list;
        for (std::list<ASTNode *>::iterator it = list.begin(); it != list.end(); ++it) {
            ASTNode *nn = *it;
            nn->accept(this);
            std::string tmp_var = getTempName();
            ins_list.push_back(Instrument(
                Instrument::Type::I_COPY,
                tmp_var,
                result_name
            ));
            temp_list.push_back(tmp_var);
        }
    }
    
    if (n->var_list) {
        std::list<std::string>::iterator it = temp_list.begin();
        std::list<ASTNode *>& list = dynamic_cast<ASTVarList*>(n->var_list)->list;
        for (std::list<ASTNode *>::iterator it_ = list.begin(); it_ != list.end(); ++it_) {
            ASTNode *nn = *it_; 
            nn->accept(this);
            ins_list.push_back(Instrument(
                Instrument::Type::I_MOVE,
                result_name,
                (it == temp_list.end() ? "nil" : *(it++))
            ));
        }
    }
}

void NaiveCompiler::visit(ASTExprList *) {}

void NaiveCompiler::visit(ASTVarList *) {}

void
NaiveCompiler::visit(ASTBinaryExpr *n)
{
    n->left->accept(this);
    std::string left_temp = result_name;
    
    n->right->accept(this);
    std::string right_temp = result_name;
    
    Instrument::Type type = Instrument::Type::I_UNKNOWN;
    
    switch (n->op) {
        case ASTBinaryExpr::Operator::O_ADD:
            type = Instrument::Type::I_ADD;
            break;
        case ASTBinaryExpr::Operator::O_SUB:
            type = Instrument::Type::I_SUB;
            break;
        case ASTBinaryExpr::Operator::O_MUL:
            type = Instrument::Type::I_MUL;
            break;
        case ASTBinaryExpr::Operator::O_DIV:
            type = Instrument::Type::I_DIV;
            break;
        case ASTBinaryExpr::Operator::O_MOD:
            type = Instrument::Type::I_MOD;
            break;
        case ASTBinaryExpr::Operator::O_AND:
            type = Instrument::Type::I_LAND;
            break;
        case ASTBinaryExpr::Operator::O_OR:
            type = Instrument::Type::I_LOR;
            break;
        case ASTBinaryExpr::Operator::O_EQ:
            type = Instrument::Type::I_EQ;
            break;
        default:
			char kkkk[256];
			sprintf(kkkk, "%d", static_cast<int>(n->op));
            throw Exception("Binary Operator unsupport",
                std::string(kkkk));
    }
    
    result_name = getTempName();
    ins_list.push_back(Instrument(
        type,
        result_name,
        left_temp,
        right_temp
    ));
}

void
NaiveCompiler::visit(ASTUnaryExpr *n)
{
    n->oprand->accept(this);
    std::string oprand_temp = result_name;
    
    std::string left_temp = getGlobalRuntime()->newLiteral(
        getGlobalRuntime()->newNumber(0).get()
        );
        
    Instrument::Type type = Instrument::Type::I_UNKNOWN;
    switch(n->op) {
        case ASTUnaryExpr::Operator::O_SUB:
            type = Instrument::Type::I_SUB;
            break;
        case ASTUnaryExpr::Operator::O_ADD:
            type = Instrument::Type::I_ADD;
            break;
        case ASTUnaryExpr::Operator::O_NOT:
            type = Instrument::Type::I_LNOT;
            break;
        default:
            throw Exception("Unary Operator unsupport");
    }
    
    result_name = getTempName();
    ins_list.push_back(Instrument(
        type,
        result_name,
        left_temp,
        oprand_temp
    ));
}

void
NaiveCompiler::visit(ASTOffsetExpr *n)
{
    n->oprand->accept(this);
    std::string oprand_temp = result_name;
    
    n->offset->accept(this);
    std::string offset_temp = result_name;
    
    result_name = getTempName();
    ins_list.push_back(Instrument(
        Instrument::Type::I_INDEX,
        result_name,
        oprand_temp,
        offset_temp
    ));
}

void
NaiveCompiler::visit(ASTID *n)
{ result_name = n->name; }

void
NaiveCompiler::visit(ASTNumber *n)
{
    result_name = getGlobalRuntime()->newLiteral(
        getGlobalRuntime()->newNumber(n->value).get()
    );
}

void
NaiveCompiler::visit(ASTString *n)
{
    result_name = getGlobalRuntime()->newLiteral(
        getGlobalRuntime()->newString(n->value).get()
    );
}

void
NaiveCompiler::visit(ASTBoolean *n)
{
    result_name = getGlobalRuntime()->newLiteral(
        getGlobalRuntime()->newBoolean(n->value).get()
    );
}

void
NaiveCompiler::visit(ASTLabel *n)
{
    ins_list.push_back(Instrument(
        Instrument::Type::I_LABEL,
        n->name
    ));
}

void
NaiveCompiler::visit(ASTGoto *n)
{
    ins_list.push_back(Instrument(
        Instrument::Type::I_GOTO,
        "::" + n->dist + "::"
    ));
}

void
NaiveCompiler::visit(ASTIf *n)
{
    std::string then_label = getGlobalRuntime()->newTempLabel();
    std::string end_label = getGlobalRuntime()->newTempLabel();
    
    n->condition->accept(this);
    ins_list.push_back(Instrument(
        InstrumentType::I_GOTOIF,
        then_label,
        result_name
    ));
    
    if (n->else_stmt)
        n->else_stmt->accept(this);
    ins_list.push_back(Instrument(
        InstrumentType::I_GOTO,
        end_label
    ));
    ins_list.push_back(Instrument(
        InstrumentType::I_LABEL,
        then_label
    ));
    if (n->then_stmt)
        n->then_stmt->accept(this);
    ins_list.push_back(Instrument(
        InstrumentType::I_LABEL,
        end_label
    ));
}