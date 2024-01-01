#include "queue.h"

QNode* newQNode(TokenNode* tokenNode) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->val = tokenNode;
    temp->next = NULL;
    return temp;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int enqueue(Queue* queue, TokenNode* tokenNode) {
    QNode* temp = newQNode(tokenNode);

    if (queue->rear == NULL) {
        queue->front = temp;
        queue->rear = temp;
        return 1;
    }

    queue->rear->next = temp;
    queue->rear = temp;
    return 1;

}

TokenNode* dequeue(Queue* queue) {

    if (queue->front == NULL) { return NULL; }

    QNode* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) { queue->rear = NULL; }

    return temp->val;

}

