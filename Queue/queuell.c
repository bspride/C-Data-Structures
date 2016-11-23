#include "queuell.h"

queue * queue_init() {
  queue *q = malloc(size_of(node));
  
  q->size = 0;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

// adds value at position at tail
void enqueue(queue *q, int value) {
  node *newNode = malloc(size_of(node));
  newNode->value = value;
  newNode->next = NULL;

  if(q->tail) {
    q->tail->next = newNode;
  }
  q->tail = newNode;

  if(empty(q)) {
    q->head = newNode;
    q->tail = newNode;
  }
}

// returns value and removes least recently added element (front)
int dequeue(queue *q) {
  if(empty(q)) {
    exit(EXIT_FAILURE);
  }

  int value = q->head->value;
  node *temp = q->head;

  if(q->tail == q->head) {
    q->tail = NULL;
  }

  q->head = q->head->next;

  free(temp);

  return value;
}

bool empty(queue *q) {
  return q->head == NULL;
}