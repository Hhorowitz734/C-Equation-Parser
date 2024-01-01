#include "stack.h"

Stack* initStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    stack->val = NULL;
    stack->next = NULL;
    return stack;
}

 
int isEmpty(Stack* s) {
    if (s->val == NULL && s->next == NULL) { return 1; }
    return 0;
}

int push(Stack** s, TokenNode* newNode) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        // Handle memory allocation failure
        return 1; // Error code
    }
    newStack->val = newNode;
    newStack->next = *s;
    *s = newStack;
    return 0; // No errors
}

TokenNode* pop(Stack** s) {
    if (*s == NULL) {
        // Handle empty stack
        return NULL;
    }
    Stack* temp = *s;
    TokenNode* value = temp->val;
    *s = temp->next;
    free(temp);
    return value;
}
