#ifndef __LEXER_H
#define __LEXER_H
#include <iostream>

class Lexer{

    public:
    Lexer(std::string sourceCode){

        source = sourceCode;
        cursor = 0;
        size = sourceCode.length();
        current = sourceCode.at(cursor);
    }

    private:
        std::string source;
        int cursor;
        int size;
        char current;
};

#endif
