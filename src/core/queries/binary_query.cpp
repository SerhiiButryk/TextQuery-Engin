#include "binary_query.h"

#include <utility>

namespace PROG
{
    BinaryQuery::BinaryQuery(const Query& q1, const Query& q2) : left(q1), right(q2) {}

    QueryResult BinaryQuery::eval(const TextView& text) const
    {
        const auto& lines = text.getLines();

        if (lines.empty()) 
            return QueryResult();

        QueryResult queryResultLeft;
        QueryResult queryResultRight;

        if (!left.isEqualToOperation(OPSIMPLE)) 
        {
           auto result = left.eval(text);

           if (!result.isEmpty())
           {
               queryResultLeft = std::move(result);
           }

        }

        if (!right.isEqualToOperation(OPSIMPLE)) 
        {
           auto result = right.eval(text);

           if (!result.isEmpty())
           {
               queryResultRight = std::move(result);
           }

        }

        QueryResult result;

        if (!queryResultLeft.isEmpty() && !queryResultRight.isEmpty()) 
        {

            result = evalResult(queryResultLeft, queryResultRight);

        } else {

            // Simple search
            std::string leftQuery = left.rep();
            std::string rightQuery = right.rep();

            // Overriden by subclasses
            result = executeSearch(lines, leftQuery, rightQuery);

        }

        // Return result
        return result;
    }

} 