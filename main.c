#include <stdio.h>
#include "include/parser.h"

#include "include/visualizer.h"

int main() { 

    char* input = "(1 / 2) + (3 * 4)";
    TokenNode* root = getRoot(input);



    showTree(root);
}