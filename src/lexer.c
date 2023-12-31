#include "../include/lexer.h"

Token tokenizeString(char* input, int start, int *end) {
    Token token;
    token.lexeme = (char*) malloc(*end - start + 1);
    strncpy(token.lexeme, input + start, *end - start);
    return token;
}

Token atom(char* input, int start, int *end, TokenType token_type) {
    (*end)++;
        
    Token token = tokenizeString(input, start, end);
    token.type = token_type;
    return token;
}

Token numeric(char* input, int start, int *end){

    bool period_used = false;

    while (isdigit(input[*end]) || (input[*end] == '.' && !period_used)) {
        
        if (input[*end] == '.') { period_used = true; }
        (*end)++;

    }

    Token token = tokenizeString(input, start, end);
    if (period_used) { token.type = T_FLT; }
    else { token.type = T_INT; }
    return token;
    
}

TokenType GetOperatorType(char opr) {
    switch (opr) {
        case '+': return T_PLS;
        case '-': return T_MNS;
        case '*': return T_MLT;
        case '/': return T_DVD;
        default: return T_ERR; 
    }
}

TokenType GetGroupingType(char grp) {
    switch (grp) {
        case '(': return T_POP;
        case ')': return T_PCL;
        default: return T_ERR;
    }
}


Token nextToken(char* input, int *position) {

    char curr = input[*position];

    while (isspace(curr)) {
        (*position)++;
        curr = input[*position];
    }

    int start = *position; // Start position of lexeme

    //Handling number token
    if (isdigit(curr)) { return numeric(input, start, position); }

    //Handling operator token
    if (GetOperatorType(curr) != T_ERR) {
        Token t = atom(input, start, position, GetOperatorType(curr));
        curr = input[*position];
        return t;
    }

    //Handling grouping token
    if (GetGroupingType(curr) != T_ERR) {
        Token t = atom(input, start, position, GetGroupingType(curr));
        curr = input[*position];
        return t;
    }

    
    //Error token
    Token token;
    token.lexeme = "Error constructing token";
    token.type = T_ERR;
    return token;
}
