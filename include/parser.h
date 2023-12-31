#ifndef PARSER_H
#define PARSER_H 

#include "lexer.h"

typedef struct {

    // Token and its type
    Token* token;
    TokenType tokenType;

    // Left and right children of node
    Token* left;
    Token* right;
    
} TokenNode;




#endif