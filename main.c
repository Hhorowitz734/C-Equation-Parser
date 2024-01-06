#include <stdio.h>
#include "include/parser.h"

#include "include/visualizer.h"

int main() { 

    char* input = "(50 - 5) * ((5 + 3) - (4 * 4))";
    TokenNode* root = getRoot(input);



    showTree(root);
}