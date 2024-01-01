#ifndef STACK_H
#define STACK_H

#include "../include/parser.h"

typedef struct Stack {
    TokenNode* val;
    struct Stack* next;
} Stack;

/**
 * Initializes a new stack.
 *
 * Allocates memory for a new stack and sets its initial values.
 * The returned stack is empty with both `val` and `next` pointers set to NULL.
 *
 * @returns A pointer to the newly created Stack, or NULL if memory allocation fails.
 */
Stack* initStack();

/**
 * Pushes a new node onto the stack.
 *
 * This function adds a new node to the top of the stack. The stack is modified in place.
 * If the stack is empty, the new node becomes the only element. If the stack is not empty,
 * the new node is added to the top, and the rest of the stack follows it.
 *
 * @param s A pointer to the pointer of the stack to which the node will be added.
 * @param newNode A pointer to the TokenNode to be added to the stack.
 * @returns 0 if the node is successfully added, or 1 if memory allocation for the new stack node fails.
 */
int push(Stack** s, TokenNode* newNode);

/**
 * Pops the top node from the stack.
 *
 * Removes the top node from the stack and returns it. If the stack is empty, NULL is returned.
 * The stack is modified in place, and the memory of the popped stack node is freed.
 *
 * @param s A pointer to the pointer of the stack from which the top node will be removed.
 * @returns A pointer to the TokenNode that was at the top of the stack, or NULL if the stack is empty.
 */
TokenNode* pop(Stack** s);

/**
 * Checks if the stack is empty.
 *
 * Determines whether the stack has any elements. An empty stack is one where both the `val`
 * and `next` pointers are NULL.
 *
 * @param s A pointer to the stack to be checked.
 * @returns 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack* s);


#endif