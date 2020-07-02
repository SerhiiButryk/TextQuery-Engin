#include "and_query.h"

#include <algorithm>

namespace PROG
{
    AndQuery::AndQuery(const Query& q1, const Query& q2)  : BinaryQuery(q1, q2) 
    {
        repQuery = left.rep() + OPAND + right.rep();

        operation = OPAND;
    }
    
    QueryResult AndQuery::executeSearch(const std::vector<std::string>& textToSearch, 
        const std::string& left, const std::string& right) const
    {
        std::vector<size_t> foundIndexes;

        for (int i = 0; i < textToSearch.size(); i++) 
        {
            // Found
            if (textToSearch[i].find(left) != std::string::npos 
                    && textToSearch[i].find(right) != std::string::npos)
            {
                foundIndexes.push_back(i);
            }

        }    

        return QueryResult(foundIndexes);
    }

    QueryResult AndQuery::evalResult(const QueryResult& left, QueryResult& right) const
    {
        // It's AND query so add only indexes which are the same in both results
        std::vector<size_t> resultVector;
        
        resultVector.insert(resultVector.end(), 
            std::make_move_iterator(left.getVec().begin()), std::make_move_iterator(left.getVec().end()));    

        resultVector.insert(resultVector.end(), 
            std::make_move_iterator(left.getVec().begin()), std::make_move_iterator(left.getVec().end()));        

        auto firstDuplicatedElement = std::unique(resultVector.begin(), resultVector.end());

        if (firstDuplicatedElement == resultVector.end())
        {
            // No results
            return QueryResult();
        
        } else {

            std::vector<size_t> res;

            res.insert(res.begin(), firstDuplicatedElement, resultVector.end());

            return QueryResult(res);            
        }

    }

    const std::string& AndQuery::rep() const
    {
        return repQuery;
    }

} 
