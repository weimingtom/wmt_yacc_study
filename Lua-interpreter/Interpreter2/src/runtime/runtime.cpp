#include "runtime.h"
#include "scope.h"

using namespace CUA;

Scope*
Runtime::getGlobalScope()
{
    if (!global_scope)
        global_scope = new Scope(NULL);
    return global_scope;
}

Scope*
Runtime::createScope()
{ return getGlobalScope()->createChildScope(); }

std::string
Runtime::newLiteral(Value *v)
{
	char kkk[256];
	sprintf(kkk, "%d", ++literal_count);
    std::string name = Config::SCOPE_LITERAL_PREFIX 
        + std::string(kkk);
    getGlobalScope()->getReferenceByName(name)->reset(v);
    return name;
}