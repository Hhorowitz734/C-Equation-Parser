#include <stdio.h>
#include "include/lexer.h"

int main() { 

    char* input = "  (12.3 - 4) / 2 ";
    int position = 0;

    Token* token = nextToken(input, &position);

    while (token->type != T_ERR) {
        printf("Token: %s\n", token->lexeme);
        token = nextToken(input, &position);
    }
}