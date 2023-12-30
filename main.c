#include <stdio.h>
#include "src/lexer.h"

int main() { 

    char* input = "1234 + 1234 -  - 1234";
    int position = 0;

    Token token = nextToken(input, &position);



    while (token.type != T_ERR) {
        printf("Token: %s\n", token.lexeme);
        token = nextToken(input, &position);
    }
}