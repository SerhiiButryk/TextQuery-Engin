#include "word_query.h"

#include <map>

namespace PROG
{
    WordQuery::WordQuery(const std::string& _query) : QueryBase(), query(_query) 
    {
        operation = OPSIMPLE;
    }
    
    QueryResult WordQuery::eval(const TextView& text) const 
    {
        // get lines
        const auto& lines = text.getLines();

        if (lines.empty()) 
            return QueryResult();

        // indexes
        std::vector<std::string::size_type> foundLines;
        
        // on each line
        for (int i = 0; i < lines.size(); i++) 
        {
            // Found
            if (lines[i].find(query) != std::string::npos)
            {
                foundLines.push_back(i);
            }

        }

        // Return result
        return QueryResult(foundLines);
    }

    const std::string& WordQuery::rep() const { return query; }

} 