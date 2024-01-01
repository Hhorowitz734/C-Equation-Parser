#include "../include/parser.h"

#include <stdio.h>

TokenNode* getRoot(char* input) {
    int position = 0;


    // Parse the highest-level component of the grammar, which is an expression
    TokenNode* root = parseExpression(input, &position);


    return root; // Return the root of the parsed expression
}


Token* consume(char* input, int *position){ return nextToken(input, position); }

Token* peek(char* input, int *position){

    int tempPosition = *position;
    Token* tempToken = nextToken(input, position);
    *position = tempPosition;

    return tempToken;

}

TokenNode* createTokenNode(Token* token, TokenType tokenType){

    TokenNode* node = (TokenNode*)malloc(sizeof(TokenNode));
    
    node->token = token;
    node->tokenType = tokenType;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int isExpected(Token* token, TokenType expected_type) { return token->type == expected_type; }



// RECURSIVE DESCENT PARSER FUNCTIONS

TokenNode* parseExpression(char* input, int* position) {

    TokenNode* leftTerm = parseTerm(input, position);
    //printf("%s\n", leftTerm->token->lexeme);
    // ^^ Should be parseTerm

    while (true) {

        Token* currToken = peek(input, position);

        //Case 1 -> We now have an operator
        if (isExpected(currToken, T_PLS) || isExpected(currToken, T_MNS)) {

            Token* opToken = consume(input, position);

            TokenNode* rightTerm = parseTerm(input, position);
            //To test, just replace with parseFactor for now
            // ^^^^ should be parseTerm

            TokenNode* expressionNode = createTokenNode(
                opToken,
                opToken->type
            );

            expressionNode->left = leftTerm;
            expressionNode->right = rightTerm;
            

            leftTerm = expressionNode;
        } else { break; }
    }

    return leftTerm;

}

TokenNode* parseTerm(char* input, int* position) {

    TokenNode* leftFactor = parseFactor(input, position);

    while (true) {

        Token* currToken = peek(input, position);

        //Case 1 -> We now have an operator
        if (isExpected(currToken, T_MLT) || isExpected(currToken, T_DVD)) {

            Token* opToken = consume(input, position);

            TokenNode* rightFactor = parseFactor(input, position);

            TokenNode* expressionNode = createTokenNode(
                opToken,
                opToken->type
            );

            expressionNode->left = leftFactor;
            expressionNode->right = rightFactor;
            

            leftFactor = expressionNode;
        } else { break; }
    }

    return leftFactor;

}

TokenNode* parseFactor(char* input, int* position) {
   
   Token* curr = peek(input, position);

   //Case 1 -> Factor is a number
   if (isExpected(curr, T_INT) || isExpected(curr, T_FLT)) {
        //REMEMBER THAT THIS FUNCTION RETURNS AN INT NOT BOOOL TYPE ^^^

        Token* num_token = consume(input, position);

        TokenNode* return_val = createTokenNode(
            num_token,
            num_token->type
        );

        return return_val;

   }

   //Case 2 -> Factor is a parenthesized expression
   if (isExpected(curr, T_POP)) {
        consume(input, position); //Consumes the opening parentheses

        TokenNode* expression_node = parseExpression(input, position);

        consume(input, position); //Consumes closing parenthesis

        return expression_node;
   }


   //HANDLE ERRORS HERE
   return NULL;
}
