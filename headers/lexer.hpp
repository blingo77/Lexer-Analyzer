#ifndef __LEXER_H
#define __LEXER_H
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

enum Type{

    TOKEN_ID, // 0
    TOKEN_INT, // 1
    TOKEN_EQUALS, // 2
    TOKEN_SEMICOLON, // 3
    TOKEN_LEFT_PAREN, // 4
    TOKEN_RIGHT_PAREN // 5

};

struct Token{

    
    Type TYPE;
    string VALUE;

};

string strTYPE(enum Type TYPE){

    /*
        Converts token types struct to a string
        Used in main.cpp
    */
    switch(TYPE){
        case TOKEN_ID:
            return "TOKEN_ID";
        case TOKEN_INT:
            return "TOKEN_INT";
        case TOKEN_EQUALS:
            return "TOKEN_EQUALS";
        case TOKEN_SEMICOLON:
            return "TOKEN_SEMICOLON";
        case TOKEN_LEFT_PAREN:
            return "TOKEN_LEFT_PAREN";
        case TOKEN_RIGHT_PAREN:
            return "TOKEN_RIGHT_PAREN";
    };
}

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
            current = (cursor < size) ? source[cursor] : '\0';
            return temp;
    }
}

    void checkAndSkip(){
        while(current == ' ' || current == '\n' || current == '\t' || current == '\r'){
            advance();
        }
    }

    Token * tokenizeID(){

        std::stringstream buffer;
        buffer << advance();

        char temp;
        while(isalnum(current) || current == '_'){

            buffer << advance();
        }

        Token * newToken = new Token();

        newToken->TYPE = TOKEN_ID;
        newToken->VALUE = buffer.str();

        return newToken;
    }

    Token * tokenizeInt(){

        std::stringstream buffer;
        while(isdigit(current)){
            
            buffer << advance();
        }

        // Token() is the struct
        Token * newToken = new Token();

        newToken->TYPE = TOKEN_INT;
        newToken-> VALUE = buffer.str();

        return newToken;
    }

    Token * tokenizeSpecial(enum Type TYPE){

        Token * newToken = new Token();
        newToken->TYPE = TYPE;
        newToken->VALUE = std::string(1, advance());

        return newToken;
    }

    std::vector<Token *> tokenize(){
        
        std::vector<Token *> tokens;
        bool notEOF = true;

        
        while(cursor < size && notEOF){
            checkAndSkip();

            // The logic for checking if their is an ID
            if(isalpha(current) || current == '_'){  
                tokens.push_back(tokenizeID());
                continue;
            }

            // This is the logic for defining integers
            if(isdigit(current)){

                tokens.push_back(tokenizeInt());
                continue;
            }

            switch(current){

                case ';':
                    tokens.push_back(tokenizeSpecial(TOKEN_SEMICOLON));
                    break;
                case '=':
                    tokens.push_back(tokenizeSpecial(TOKEN_EQUALS));
                    break;
                case '(':
                    tokens.push_back(tokenizeSpecial(TOKEN_LEFT_PAREN));
                    break;
                case ')':
                    tokens.push_back(tokenizeSpecial(TOKEN_RIGHT_PAREN));
                    break;
                default:
                    std::cout << " !ERROR: UNIDENTIFIED SYMBOL" << current;
                    exit(1);
            }
        }
        
       return tokens;
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
