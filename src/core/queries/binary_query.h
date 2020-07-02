#pragma once

#include "query_base.h"
#include "../query.h"
#include "../query_result.h"

namespace PROG
{

    /**
     *  Base for binary query classes
     */

    class BinaryQuery : public QueryBase
    {
        public:
            BinaryQuery(const Query& q1, const Query& q2);

        protected:
            // Override to redefine search algorithm
            virtual class QueryResult executeSearch(const std::vector<std::string>& textToSearchIn, const std::string& left, 
                const std::string& right) const = 0;

            // Implements template operations
            class QueryResult eval(const TextView& text) const override;

            // Combines results into final
            virtual QueryResult evalResult(const QueryResult& left, QueryResult& right) const = 0;

        protected:    
            Query left;
            Query right;

            void executeSubSearch();
            
    };
} 
