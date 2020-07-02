#include "not_query.h"

namespace PROG
{
    NotQuery::NotQuery(const Query& _query) : QueryBase(), query(_query) 
    {
        using namespace std::literals::string_literals;

        repQuery = "~"s + _query.rep();
    }

    QueryResult NotQuery::eval(const TextView& text) const 
    {
        // get lines
        const auto& lines = text.getLines();
        const auto& queryStr = query.rep();

        if (lines.empty()) 
            return QueryResult();

        // indexes
        std::vector<std::string::size_type> foundLines;

        // on each line
        for (int i = 0; i < lines.size(); i++) 
        {
            // Not found
            if (lines[i].find(queryStr) == std::string::npos)
            {
                foundLines.push_back(i);
            }

        }

        // Return result
        return QueryResult(foundLines);
    }

    const std::string& NotQuery::rep() const { return repQuery; }

    const std::string& NotQuery::getOperationReprsentation() const { return repQuery; }
}