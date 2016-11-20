#ifndef _CUA_NAIVE_COMPILER_H_
#define _CUA_NAIVE_COMPILER_H_

#include <list>

#include "compiler.h"

namespace CUA {
    class NaiveCompiler : public Compiler
    { 
    private:
        std::string result_name;// = "";
        Config::T_OID temp_var_counter;// = 0;
        
        inline std::string
        getTempName()
        {
			char kkk[256];
			sprintf(kkk, "%d", ++temp_var_counter);
            return 
                Config::SCOPE_COMPILE_TEMP_PREFIX +
                std::string(kkk); 
        }
        
    public:
        InstrumentList ins_list;
        
        NaiveCompiler()
        :result_name("")
        ,temp_var_counter(0) {};
        virtual ~NaiveCompiler() {};
        virtual InstrumentList compile(ASTNode *);
        
        visitor_definations
    };
}

#endif // _CUA_NAIVE_COMPILER_H_