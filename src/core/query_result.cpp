#include "query_result.h"

#include <algorithm>

namespace PROG
{
    QueryResult::QueryResult(const std::vector<size_t>& _result) : foundIndexes(_result) {}

    QueryResult::Result QueryResult::getResult(const TextView& text) const 
    {
        const auto& lines = text.getLines();
        std::map<size_t, const std::string&> foundLines;

        for (auto& index : foundIndexes)
        {
            foundLines.insert(std::pair<size_t, const std::string&>(index, lines[index]));        
        }
    
        return foundLines; 
    }

    bool QueryResult::isEmpty() const { return foundIndexes.empty(); }

    void QueryResult::addResult(const QueryResult& result)
    {
        foundIndexes.insert(foundIndexes.end(), 
            std::make_move_iterator(result.foundIndexes.begin()), std::make_move_iterator(result.foundIndexes.end()));    

        // Remove duplicates
        auto last = std::unique(foundIndexes.begin(), foundIndexes.end());

        foundIndexes.erase(last, foundIndexes.end());
    }

    const std::vector<size_t>& QueryResult::getVec() const { return foundIndexes; }

}