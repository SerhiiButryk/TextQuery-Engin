#pragma once

#include <string>

#include "../query_result.h"
#include "text_view.h"

namespace PROG
{

    class QueryBase
    {
        public:
            QueryBase() = default;
            virtual ~QueryBase() = default;

            QueryBase(const QueryBase&) = default;
            QueryBase& operator=(const QueryBase&) = default;
            
            QueryBase(QueryBase&&) noexcept = default;
            QueryBase& operator=(QueryBase&&) noexcept = default;

            virtual class QueryResult eval(const TextView& text) const = 0;
            virtual const std::string& rep() const = 0;

            const std::string& getOperationReprsentation() const;    
            
        protected:

            static const std::string OPAND; 
            static const std::string OPOR; 
            static const std::string OPNOT; 
            static const std::string OPSIMPLE;

            std::string operation;     
    };

}