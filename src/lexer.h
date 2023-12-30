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


} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
} Token;

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
        Token token;
        token.type = T_INT;

        token.lexeme = (char*) malloc(*position - start + 1);
        strncpy(token.lexeme, input + start, *position - start);

        return token;
    }

    Token token;
    token.lexeme = "Didnt work";
    return token;
}

#endif // LEXER_H
