#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "../include/parser.h"

typedef struct QNode {
    TokenNode* val;
    struct QNode* next;
} QNode;

typedef struct Queue {
    struct QNode *front;
    struct QNode *rear;
} Queue;

/**
 * Creates a new queue node.
 *
 * Allocates memory for a new QNode and initializes it with a given TokenNode.
 * The new node's 'next' pointer is set to NULL.
 *
 * @param tokenNode A pointer to a TokenNode that the new queue node will contain.
 * @returns A pointer to the newly created QNode, or NULL if memory allocation fails.
 */
QNode* newQNode(TokenNode* tokenNode);

/**
 * Initializes a new queue.
 *
 * Allocates memory for a new Queue and initializes its 'front' and 'rear' pointers to NULL,
 * indicating that the queue is initially empty.
 *
 * @returns A pointer to the newly created Queue, or NULL if memory allocation fails.
 */
Queue* createQueue();

/**
 * Adds a new node to the rear of the queue.
 *
 * Creates a new QNode with the given TokenNode and adds it to the end of the queue.
 * If the queue is empty, the new node becomes both the front and rear of the queue.
 * Otherwise, it is added as the new rear.
 *
 * @param queue A pointer to the Queue to which the new node will be added.
 * @param tokenNode A pointer to the TokenNode to be added to the queue.
 * @returns 1 on successful addition to the queue.
 */
int enqueue(Queue* queue, TokenNode* tokenNode);

/**
 * Removes and returns the front node from the queue.
 *
 * Removes the front node from the queue and returns the contained TokenNode.
 * If the queue is empty, NULL is returned. If the queue has only one node, both 
 * the front and rear pointers of the queue are set to NULL after removal.
 *
 * @param queue A pointer to the Queue from which the front node will be removed.
 * @returns The TokenNode contained in the removed front node, or NULL if the queue is empty.
 */
TokenNode* dequeue(Queue* queue);


#endif