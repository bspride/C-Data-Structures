#include "queue.h"

void queue_init(queue *q, int size) {
  q->capacity = size;
  q->size = 0;
  q->data = (int *)malloc(size_of(int) * q->capacity);
}

// Adds item at end of available storage
void enqueue(queue *q, int value) {

}

// Returns value and removes least recently added element
int dequeue(queue *q) {

}

// Checks if queue is empty
bool empty(queue *q) {
  return q->size == 0;
}

// Check is queue is full
bool full(queue *q) {
  return q->size == q->capacity;
}