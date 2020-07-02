#pragma once

#include "../query_base.h"

namespace PROG
{
    class WordQuery final : public QueryBase
    {
        public:
            explicit WordQuery(const std::string& query);

            QueryResult eval(const TextView& text) const override;

            const std::string& rep() const override;

        private:

            std::string query;    

            
    };  
} 
