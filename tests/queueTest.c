#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../utils/queue.h"  

void test_queue_creation(void) {
    Queue* q = createQueue();
    CU_ASSERT_PTR_NOT_NULL(q);
    CU_ASSERT_PTR_NULL(q->front);
    CU_ASSERT_PTR_NULL(q->rear);
    free(q);  // Clean up
}


void test_enqueue(void) {
    Queue* q = createQueue();
    TokenNode* node1 = malloc(sizeof(TokenNode));  // Assume TokenNode initialization
    enqueue(q, node1);
    CU_ASSERT_PTR_EQUAL(q->front->val, node1);
    CU_ASSERT_PTR_EQUAL(q->rear->val, node1);

    TokenNode* node2 = malloc(sizeof(TokenNode));  // Assume TokenNode initialization
    enqueue(q, node2);
    CU_ASSERT_PTR_EQUAL(q->rear->val, node2);
    CU_ASSERT_PTR_EQUAL(q->front->next->val, node2);

    // Clean up
    free(node1);
    free(node2);
    free(q->front);
    free(q->rear);
    free(q);
}


void test_dequeue(void) {
    Queue* q = createQueue();
    TokenNode* node1 = malloc(sizeof(TokenNode));  // Assume TokenNode initialization
    TokenNode* node2 = malloc(sizeof(TokenNode));  // Assume TokenNode initialization

    enqueue(q, node1);
    enqueue(q, node2);

    TokenNode* dequeued = dequeue(q);
    CU_ASSERT_PTR_EQUAL(dequeued, node1);
    CU_ASSERT_PTR_EQUAL(q->front->val, node2);

    dequeued = dequeue(q);
    CU_ASSERT_PTR_EQUAL(dequeued, node2);
    CU_ASSERT_PTR_NULL(q->front);

    // Clean up
    free(node1);
    free(node2);
    free(q);
}

void test_in_depth(void) {

    Queue* q = createQueue();

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

    enqueue(q, node);

    enqueue(q, node);

    dequeue(q);

    TokenNode* returned = dequeue(q);

    CU_ASSERT_STRING_EQUAL(returned->token->lexeme, token->lexeme);

    free(node);
    free(token);
    free(q);


}


int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Queue_Test_Suite", NULL, NULL);
    CU_add_test(suite, "test of queue creation", test_queue_creation);
    CU_add_test(suite, "test of enqueue", test_enqueue);
    CU_add_test(suite, "test of dequeue", test_dequeue);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

