#include <stdio.h>
#include "src/lexer.h"

int main() { 

    char* input = " 1234 ";
    int position = 0;

    Token token = nextToken(input, &position);

    printf("Token: %s\n", token.lexeme);
}