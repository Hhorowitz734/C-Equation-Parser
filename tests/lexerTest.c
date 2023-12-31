#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../include/lexer.h"

void basic_parsing_test(void) {
    char* parsing_input = "( 21 + 34 )";
    
    const char* expected_lexemes[] = {
        "(",
        "21",
        "+",
        "34",
        ")"
    };

    int position = 0;

    Token* token;

    for (int i = 0; i < 5; i++) {

        token = nextToken(parsing_input, &position);

        if (token == NULL) { break; }
        
        CU_ASSERT_STRING_EQUAL(token->lexeme, expected_lexemes[i]);

    }

}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Lexer_Test_Suite", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add your test to the suite
    if (NULL == CU_add_test(suite, "Test Basic Parsing", basic_parsing_test)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
