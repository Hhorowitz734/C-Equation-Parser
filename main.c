#include <stdio.h>
#include "include/parser.h"

int main() { 

    char* input = "(3 * 2) + (3 + 4)";
    TokenNode* root = getRoot(input);

    printf("%s\n", root->token->lexeme);
    printf("%s\n", root->left->token->lexeme);
    printf("%s\n", root->left->left->token->lexeme);
    printf("%s\n", root->left->right->token->lexeme);
    printf("%s\n", root->right->token->lexeme);
    printf("%s\n", root->right->left->token->lexeme);
    printf("%s\n", root->right->right->token->lexeme);
}