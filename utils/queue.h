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

QNode* newQNode(TokenNode* tokenNode);

Queue* createQueue();

int enqueue(Queue* queue, TokenNode* tokenNode);

TokenNode* dequeue(Queue* queue);


#endif