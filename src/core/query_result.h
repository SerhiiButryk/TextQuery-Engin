#pragma once

#include <map>

#include "queries/text_view.h"

namespace PROG
{
    class QueryResult
    {
        public:
            using Result = std::map<size_t, const std::string&>;

            QueryResult() = default;
            explicit QueryResult(const std::vector<size_t>& result);

            QueryResult(const QueryResult&) = default;
            QueryResult& operator=(const QueryResult&) = default;

            QueryResult(QueryResult&&) noexcept = default;
            QueryResult& operator=(QueryResult&) noexcept = default;

            Result getResult(const TextView& text) const;
            void addResult(const QueryResult& result);
            bool isEmpty() const;

            const std::vector<size_t>& getVec() const;

        private:
            std::vector<size_t> foundIndexes;
            
    };
    
}
