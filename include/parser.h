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

typedef struct TokenNode {

    // Token and its type
    Token* token;
    TokenType tokenType;

    // Left and right children of node
    struct TokenNode* left;
    struct TokenNode* right;

} TokenNode;

// RECURSIVE DESCENT FUNCTIONS

/**
 * @brief Parses an expression from the input string.
 * 
 * This function is responsible for parsing expressions which involve
 * addition and subtraction operations. It constructs and returns a parse
 * tree representing the expression. The parsing is done recursively, and
 * it involves calling parseTerm for handling the terms within the expression.
 * 
 * @param input The input string containing the expression to be parsed.
 * @param position Pointer to the current position in the input string.
 * 
 * @returns A pointer to the root node of the parse tree representing the parsed expression.
 */
TokenNode* parseExpression(char* input, int* position);

/**
 * @brief Parses a term from the input string.
 * 
 * This function handles the parsing of terms, which are components of expressions
 * typically involving multiplication and division operations. It builds and returns
 * a parse tree representing the term. The function may recursively call parseFactor
 * to handle individual factors within the term.
 * 
 * @param input The input string containing the term to be parsed.
 * @param position Pointer to the current position in the input string.
 * 
 * @returns A pointer to the root node of the parse tree representing the parsed term.
 */
TokenNode* parseTerm(char* input, int* position);

/**
 * @brief Parses a factor from the input string.
 * 
 * A factor is the most basic unit in an expression, typically a number or
 * a parenthesized sub-expression. This function parses a single factor and
 * returns a parse tree node representing it. In case of a parenthesized
 * expression, it recursively calls parseExpression.
 * 
 * @param input The input string containing the factor to be parsed.
 * @param position Pointer to the current position in the input string.
 * 
 * @returns A pointer to the node representing the parsed factor.
 */
TokenNode* parseFactor(char* input, int* position);


/**
 * @brief Creates a parsing tree for an input string
 * 
 * @param input The input string to be evaluated
 * 
 * @returns The root TokenNode* of the parsing tree
*/
TokenNode* getRoot(char* input);

// UTILITY FUNCTIONS


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