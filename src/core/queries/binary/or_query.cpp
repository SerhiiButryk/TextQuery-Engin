#include "or_query.h"

namespace PROG
{
    OrQuery::OrQuery(const Query& q1, const Query& q2)  : BinaryQuery(q1, q2)
    {
        repQuery = left.rep() + OPOR + right.rep();

        operation = OPOR;
    }

    QueryResult OrQuery::executeSearch(const std::vector<std::string>& textToSearchIn, 
            const std::string& left, const std::string& right) const
    {

        std::vector<size_t> foundIndexes;

        for (int i = 0; i < textToSearchIn.size(); i++) 
        {
            // Found
            if (textToSearchIn[i].find(left) != std::string::npos 
                    || textToSearchIn[i].find(right) != std::string::npos)
            {
                foundIndexes.push_back(i);
            }

        }    

        return QueryResult(foundIndexes);
    }

    QueryResult OrQuery::evalResult(const QueryResult& left, QueryResult& right) const
    {
        // It's OR query so we just merge two into one
        QueryResult result;

        result.addResult(left);
        result.addResult(right);

        return result;
    }

    const std::string& OrQuery::rep() const { return repQuery; }

} 
