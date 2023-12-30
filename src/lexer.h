#ifndef LEXER_H
#define LEXER_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



typedef enum {

    T_INT, //integer
    T_FLT, //float
    T_STR, //string
    
    T_PLS, //plus
    T_MNS, //minus
    T_MLT, //multiplication
    T_DVD, //division

    T_ERR //error


} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
} Token;

Token tokenizeString(char* input, int start, int *end) {
    Token token;
    token.lexeme = (char*) malloc(*end - start + 1);
    strncpy(token.lexeme, input + start, *end - start);
    return token;
}

Token nextToken(char* input, int *position) {

    char curr = input[*position];

    while (isspace(curr)) {
        (*position)++;
        curr = input[*position];
    }

    int start = *position; // Start position of lexeme

    //Handling number token

    while (isdigit(curr)) {
        (*position)++;
        curr = input[*position];
    }
    if (*position != start) {
        Token token = tokenizeString(input, start, position);
        token.type = T_INT;
        return token;
    }

    //Handling operator token
    if (curr == '+') {
        (*position)++;
        curr = input[*position];
        
        Token token = tokenizeString(input, start, position);
        token.type = T_PLS;
        return token;
    }

    if (curr == '-') {
        (*position)++;
        curr = input[*position];
        
        Token token = tokenizeString(input, start, position);
        token.type = T_MNS;
        return token;
    }

    if (curr == '*') {
        (*position)++;
        curr = input[*position];
        
        Token token = tokenizeString(input, start, position);
        token.type = T_MLT;
        return token;
    }

    if (curr == '/') {
        (*position)++;
        curr = input[*position];
        
        Token token = tokenizeString(input, start, position);
        token.type = T_DVD;
        return token;
    }

    Token token;
    token.lexeme = "Error constructing token";
    token.type = T_ERR;
    return token;
}

#endif // LEXER_H
