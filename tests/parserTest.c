#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/parser.h"  


void test_peek(void) {

    char* input = "(2 + 4)";
    int position = 0;

    Token* expected = (Token*)malloc(sizeof(Token));
    expected->type = T_POP;
    expected->lexeme = "(";

    Token* result = peek(input, &position);
    CU_ASSERT_STRING_EQUAL(result->lexeme, expected->lexeme);

}

void test_consume(void) {

    char* input = "(2 + 4)";
    int position = 0;

    Token* expected = (Token*)malloc(sizeof(Token));
    expected->type = T_INT;
    expected->lexeme = "2";

    consume(input, &position); //Go past first token
    Token* result = consume(input, &position);

    CU_ASSERT_STRING_EQUAL(result->lexeme, expected->lexeme);
}

void test_is_expected(void) {

    Token* expected = (Token*)malloc(sizeof(Token));
    expected->type = T_INT;
    expected->lexeme = "2";

    CU_ASSERT_EQUAL(isExpected(expected, T_INT), 1);
}

void base_expression_test(void) {

    char* input = "(3 * 4) + 5";

    TokenNode* root = getRoot(input);

    CU_ASSERT_STRING_EQUAL(root->token->lexeme, "+");

    // Check left subtree
    CU_ASSERT_STRING_EQUAL(root->left->token->lexeme, "*");
    CU_ASSERT_STRING_EQUAL(root->left->left->token->lexeme, "3");
    CU_ASSERT_STRING_EQUAL(root->left->left->token->lexeme, "4");

    // Check right subtree
    CU_ASSERT_STRING_EQUAL(root->right->token->lexeme, "5");
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Queue_Test_Suite", NULL, NULL);
    CU_add_test(suite, "Testing peek", test_peek);
    CU_add_test(suite, "Testing consume", test_consume);
    CU_add_test(suite, "Testing isExpected", test_is_expected);
    CU_add_test(suite, "Test parsing of a basic expression", base_expression_test);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

