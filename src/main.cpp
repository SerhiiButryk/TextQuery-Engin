#include <iostream>

#include "core/query.h"

using PROG::Query;
using PROG::QueryResult;
using PROG::TextView;

using namespace std::literals::string_literals;

int main() {

    auto text =

    "That if thou shalt confess with thy\n"s
    "mouth the Lord Jesus, and shalt believe\n"s
    "in thine heart that God hath raised him\n "s
    "from the dead, thou shalt be saved.\n "s
    "For with the heart man believeth unto righteousness;\n "s
    "and with the mouth confession is made unto salvation.\n "s
    "For whosoever shall call upon \n"s
    "the name of the Lord shall be saved\n"s;

    TextView textContainer(text);

    Query q = Query("and"s) & Query("the"s) | ~Query("the"s);

    auto result = q.eval(textContainer);

    if (!result.isEmpty()) 
    {
        auto lines = result.getResult(textContainer);

        std::cout << "\nExecuted query: " << q.rep() << "\n\n";  

        for (auto& v : lines)
        {
            std::cout << "Line (" << v.first  << ") : "  << v.second << "\n";  
        } 

        std::cout << "\n";  
    
    } else {

        std::cout << "No result \n";  
    }

}   