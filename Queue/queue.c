#include "queue.h"

void queue_init(queue *q, int size) {
  q->capacity = size;
  q->size = 0;
  q->data = (int *)malloc(size_of(int) * q->capacity);
}