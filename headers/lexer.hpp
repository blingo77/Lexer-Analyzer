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

    char advance(){ // returns character at position and moves cursor forward

        if (cursor < size){

            char temp = current;
            cursor++;

            if(cursor < size){
                current = source[cursor];
            }
            else{
                current = '\0';
            }
        }
        else{
            return '\0';
        }
    }

    char peak(int offset = 0){

        if(cursor + offset < size){ // checks if the cursor + offset is in the bouds of source
            return source[cursor + offset];
        }
        else{
            return '\0';
        }
    }

    private:
        // the source code from main.cpp
        std::string source;
        // the index of the source
        int cursor;
        // size of the source
        int size;
        // current charcter of the source
        char current;
};

#endif
