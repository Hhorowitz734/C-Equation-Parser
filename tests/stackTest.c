#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../utils/stack.h"  // Include the correct path to your stack header file

void test_stack_initialization(void) {
    Stack* s = initStack();
    CU_ASSERT_PTR_NOT_NULL(s);
    CU_ASSERT_PTR_NULL(s->val);
    CU_ASSERT_PTR_NULL(s->next);
    free(s);
}

void test_is_empty(void) {
    Stack* s = initStack();
    CU_ASSERT_TRUE(isEmpty(s));
    free(s);
}

void test_push_and_pop(void) {
    Stack* s = initStack();

    // Replace with your actual TokenNode structure and initialization
    TokenNode* node1 = malloc(sizeof(TokenNode));
    // Initialize node1 as needed

    push(&s, node1);
    CU_ASSERT_FALSE(isEmpty(s));

    TokenNode* node2 = malloc(sizeof(TokenNode));
    // Initialize node2 as needed

    push(&s, node2);

    // Pop and check
    TokenNode* popped = pop(&s);
    CU_ASSERT_PTR_NOT_NULL(popped);
    // Add more assertions as needed based on your TokenNode structure
    free(popped);

    popped = pop(&s);
    CU_ASSERT_PTR_NOT_NULL(popped);
    // Add more assertions as needed
    free(popped);

    CU_ASSERT_TRUE(isEmpty(s));

    // Clean up
    free(s);
}

void test_in_depth(void) {

    Stack* s = initStack();

      // Allocating and initializing a Token
    Token* token = malloc(sizeof(Token));
    token->type = T_INT;
    token->lexeme = "1234";  // Example integer value as a string

    // Allocating and initializing a TokenNode
    TokenNode* node = malloc(sizeof(TokenNode));
    node->token = token;
    node->tokenType = token->type;
    node->left = NULL;
    node->right = NULL;

    push(&s, node);

    TokenNode* retrieved_token = pop(&s);

    CU_ASSERT_STRING_EQUAL(retrieved_token->token->lexeme, token->lexeme);


}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Stack_Test_Suite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if ((CU_add_test(suite, "Test of stack initialization", test_stack_initialization) == NULL) ||
        (CU_add_test(suite, "Test of isEmpty", test_is_empty) == NULL) ||
        (CU_add_test(suite, "In depth test", test_in_depth) == NULL) ||
        (CU_add_test(suite, "Test of push and pop", test_push_and_pop) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Set the mode of the test run, run the tests and clean up
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
