#pragma once

#include <vector>
#include <string>

namespace PROG
{
    class TextView
    {
        public:
            explicit TextView(const std::string& text);

            const std::vector<std::string>& getLines() const;
            
        private:
            std::vector<std::string> textLines;

            void _parse(const std::string& text);

        private:
            static const char delimiter;    
    };
}