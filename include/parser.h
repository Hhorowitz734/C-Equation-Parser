#ifndef PARSER_H
#define PARSER_H 

#include "lexer.h"

/**
 *             Planned Parser
 *  ----------------------------------------
 *  Expr   → Term (( "+" | "-" ) Term)*
    Term   → Factor (( "*" | "/" ) Factor)*
    Factor → Number | "(" Expr ")"
    Number → Int | Float
*/

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
TokenNode* getRoot(char* input);

/**
 * @brief Consumes the current token and advances the position in the input stream.
 * 
 * @param input The input string being tokenized.
 * @param position Pointer to the current position in the input string.
 * 
 * @returns The current Token* before the position is advanced.
 */
Token* consume(char* input, int *position);

/**
 * @brief Peeks at the current token in the input stream without consuming it.
 * 
 * This function retrieves the current token from the input at the given position
 * but does not advance the position, allowing a look-ahead at the next token
 * without altering the current parsing state.
 * 
 * @param input The input string being tokenized.
 * @param position Pointer to the current position in the input string.
 * 
 * @returns The current Token* without advancing the position.
 */
Token* peek(char* input, int *position);

/**
 * @brief Creates a new TokenNode with the given token and token type.
 * 
 * Allocates memory for a new TokenNode, initializes it with the provided token
 * and its type, and sets its left and right children to NULL.
 * 
 * @param token The token to be stored in the node.
 * @param tokenType The type of the token.
 * 
 * @returns A pointer to the newly created TokenNode.
 */
TokenNode* createTokenNode(Token* token, TokenType tokenType);

/**
 * @brief Checks if the token's type matches the expected type.
 * 
 * Compares the type of the given token with an expected token type and
 * returns a result indicating whether they match.
 * 
 * @param token The token whose type is to be checked.
 * @param expected_type The TokenType that is expected.
 * 
 * @returns 1 (true) if the token type matches the expected type, 0 (false) otherwise.
 */
int isExpected(Token* token, TokenType expected_type);






#endif