#include "text_view.h"

#include <utility>

namespace PROG
{
    TextView::TextView(const std::string& text) 
    {
        _parse(text);
    }

    void TextView::_parse(const std::string& text)
    {
        using stringType = std::string::size_type;

        stringType begin = 0;
        stringType end = 0;

        while ((end = text.find(delimiter, begin)) != std::string::npos )
        {
            std::string subStr = text.substr(begin, end - begin);

            textLines.push_back(std::move(subStr));

            // Move to next symbol
            begin = end + 1;
        }
        
    }

    const std::vector<std::string>& TextView::getLines() const { return textLines; }

    const char TextView::delimiter = '\n';
}