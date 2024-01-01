#ifndef PARSER_H
#define PARSER_H 

#include "lexer.h"
#include <stdio.h>

typedef struct {

    // Token and its type
    Token* token;
    TokenType tokenType;

    // Left and right children of node
    Token* left;
    Token* right;

} TokenNode;

/**
 * @brief Creates a parsing tree for an input string
 * 
 * @param input The input string to be evaluated
 * 
 * @returns The root TokenNode* of the parsing tree
*/
TokenNode* getRoot(char* input) {

    int position = 0;

    Token* token = nextToken(input, &position);

    while (token->type != T_ERR) {

        /**
        switch(token->type) {
            case T_INT:
            case T_FLT:
                // finish implementing
                // https://stackoverflow.com/questions/4582398/writing-a-simple-equation-parser
        }
        */


        printf("Token: %s\n", token->lexeme);
        token = nextToken(input, &position);
    }

}




#endif