#include "query_base.h"

namespace PROG
{
    const std::string QueryBase::OPAND = "&"; 
    
    const std::string QueryBase::OPOR = "|"; 
    
    const std::string QueryBase::OPNOT = "~"; 
    
    const std::string QueryBase::OPSIMPLE = "none"; 

    const std::string& QueryBase::getOperationReprsentation() const { return operation; }

}