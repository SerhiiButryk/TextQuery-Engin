#pragma once

#include <string>
#include <memory>

#include "query_result.h"
#include "queries/text_view.h"
#include "queries/query_base.h"

/**
 *  Interface class to work with queries.
 *  Incapsulates concrete query classes.
 */

namespace PROG
{
    class Query 
    {
        public:
            friend Query operator|(const Query& queryOne, const Query& queryTwo);
            friend Query operator&(const Query& queryOne, const Query& queryTwo);
            friend Query operator~(const Query& query);

        public:
            Query() = default;
            explicit Query(const std::string& query);

            Query(const Query&);
            Query& operator=(const Query&);

            class QueryResult eval(const TextView& text) const;

            std::string rep() const;
            
            bool isEqualToOperation(const std::string& queryOperation) const;

        private:
            explicit Query(std::shared_ptr<QueryBase>);
            
            const std::string& getInternalRepOperation() const;
            
            std::shared_ptr<QueryBase> query;

    };
}