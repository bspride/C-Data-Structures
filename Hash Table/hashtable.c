#include "hashtable.h"

hashtable hashtable_init() {
  hashtable *ht = malloc(size_of(hashtable));

  q->size = 0;
  q->capacity = 8;
  q->data = malloc(size_of(int) * q->capacity);
}

// if key already exists, update value
void add(int key, int value);
bool exists(int key);
int get(int key);
void remove(key);