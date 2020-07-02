#pragma once

#include "../binary_query.h"

namespace PROG
{

    class OrQuery final : public BinaryQuery
    {
        public:
            OrQuery(const Query& q1, const Query& q2);

            const std::string& rep() const override;

        protected:

            QueryResult executeSearch(const std::vector<std::string>& textToSearchIn, 
                const std::string& left, const std::string& right) const override;

            QueryResult evalResult(const QueryResult& left, QueryResult& right) const override;    

            std::string repQuery; 
    };
} 
