#include "query.h"

#include "queries/unary/word_query.h"
#include "queries/binary/and_query.h"
#include "queries/binary/or_query.h"
#include "queries/unary/not_query.h"

namespace PROG
{
    Query::Query(const std::string& _query) : query(std::make_shared<WordQuery>(_query)) { }

    Query::Query(std::shared_ptr<QueryBase> _query) : query(_query) {}

    Query::Query(const Query& from) 
    {
        query = from.query;
    }
    
    Query& Query::operator=(const Query& from)
    {
        if (this != &from)
        {
            query = from.query;
        }

        return *this;
    }

    QueryResult Query::eval(const TextView& text) const { return query->eval(text); }

    std::string Query::rep() const { return query->rep(); }

    Query operator|(const Query& queryOne, const Query& queryTwo)
    {
        OrQuery* orQuery = new OrQuery(queryOne, queryTwo);

        return Query(std::shared_ptr<OrQuery>(orQuery));        
    }

    Query operator&(const Query& queryOne, const Query& queryTwo)
    {
        AndQuery* andQuery = new AndQuery(queryOne, queryTwo);

        return Query(std::shared_ptr<AndQuery>(andQuery));   
    }

    Query operator~(const Query& query)
    {
        NotQuery* notQuery = new NotQuery(query);

        return Query(std::shared_ptr<NotQuery>(notQuery));   
    }

    const std::string& Query::getInternalRepOperation() const
    {
        return query->getOperationReprsentation();
    }

    bool Query::isEqualToOperation(const std::string& queryOperation) const
    {
        return getInternalRepOperation().compare(queryOperation) == 0;
    }

}