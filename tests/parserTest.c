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

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Queue_Test_Suite", NULL, NULL);
    CU_add_test(suite, "Testing peek", test_peek);
    CU_add_test(suite, "Testing consume", test_consume);
    CU_add_test(suite, "Testing isExpected", test_is_expected);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

