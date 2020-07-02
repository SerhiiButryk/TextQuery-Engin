#pragma once

#include "../query_base.h"
#include "../../query.h"

namespace PROG
{
    class NotQuery final : public QueryBase
    {
        public:
            explicit NotQuery(const Query& query);

            QueryResult eval(const TextView& text) const override;

            const std::string& rep() const override;

            const std::string& getOperationReprsentation() const;    

        private:

            Query query;   
            
            std::string repQuery;
    };
}