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

/**
 * @brief Tokenizes a part of the input string, creating Token pointer with lexeme
 * 
 * @param input Input string
 * @param start The start index of the lexeme
 * @param end The end index of the lexeme (Should be the current position)
 * 
 * @return The Token* pointer to an object with the lexeme included
 * 
 * @note Remember that the Token* pointer will NOT automatically be given a type
*/
Token* tokenizeString(char* input, int start, int *end);

/**
 * @brief Handles a one-character token such as '(' or ')'
 * 
 * @param input Input string
 * @param start The start index of the lexeme
 * @param end The end index of the lexeme (Should be start + 1)
 * @param token_type The type of the atom
 * 
 * @return The configured Token* pointer appropriate to the token type and lexeme
*/
Token* atom(char* input, int start, int *end, TokenType token_type); //To optimize this, pass a pointer instead

/**
 * @brief Handles a numeric value (int or float)
 * 
 * @param input Input string
 * @param start The start index of the lexeme
 * @param end The end index of the lexeme
 * 
 * @return The configure Token* pointer for a numeric value
 * 
 * @note Note that handling whether the number is a T_INT or T_FLT is handled automatically by this function
*/
Token* numeric(char* input, int start, int *end);

/**
 * @brief Tells us which of the grouping symbols a lexeme is, if any
 * 
 * @param grp The symbol to be evaluated
 * 
 * @returns The approprate TokenType for the grouping symbol, or T_ERR
*/
TokenType GetGroupingType(char grp);

/**
 * @brief Tells us which of the operators a lexeme is, if any
 * 
 * @param opr The symbol to be evaluated
 * 
 * @returns The approprate TokenType for the operator symbol, or T_ERR
*/
TokenType GetOperatorType(char opr);

/**
 * @brief Gets the next token in the input string
 * 
 * @param input The input string
 * @param position A reference to the position to start tokenizing from
 * 
 * @returns A pointer to the newly created token
*/
Token* nextToken(char* input, int *position);

#endif // LEXER_H
