#ifndef LEXER_H
#define LEXER_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



typedef enum {

    T_INT, //integer
    T_FLT, //float
    T_STR, //string
    
    T_PLS, //plus
    T_MNS, //minus
    T_MLT, //multiplication
    T_DVD, //division

    T_POP, // ( parenthesis open
    T_PCL, // ) parenthesis closed

    T_ERR //error


} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
} Token;

Token* tokenizeString(char* input, int start, int *end);

Token* atom(char* input, int start, int *end, TokenType token_type); //To optimize this, pass a pointer instead

Token* numeric(char* input, int start, int *end);

TokenType GetGroupingType(char grp);

Token* nextToken(char* input, int *position);

#endif // LEXER_H
