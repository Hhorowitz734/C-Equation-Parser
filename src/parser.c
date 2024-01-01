#include "../include/parser.h"

TokenNode* getRoot(char* input) {

    int position = 0;

    Token* token = nextToken(input, &position);

    while (token->type != T_ERR) {

    /**
        switch(token->type) {
            case T_INT:
            case T_FLT:
                // finish implementing a recursive descent parser
                // https://stackoverflow.com/questions/4582398/writing-a-simple-equation-parser
        }
    */

        printf("Token: %s\n", token->lexeme);
        token = nextToken(input, &position);
    }

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


