#include <assert.h>
#include <stdbool.h>

const int VECTOR_INITIAL_CAPACITY = 16;
const int GROWTH_FACTOR = 2;
const int SHRINK_FACTOR = 4;

typedef struct {
  int size;
  int capacity;
  int *data;
} Vector;

void vector_init(Vector *vector);

/* Number of items */
int vector_size(Vector *vector);

int determine_capacity(int capacity);
void resize_for_size(Vector *vector, int size);

/* Vector capacity */
int vector_capacity(Vector *vector);

/* Vector is empty */
bool vector_is_empty(Vector *vector);

/* Returns object and index */
int vector_get(Vector *vector, int index);

/* Adds item to end of vector */
void vector_push(Vector *vector, int value);

/* Adds item to vector and index */
void vector_insert(Vector *vector, int index, int value);

/* Adds item to start of vector */
void vector_prepend(Vector *vector, int value);

/* Remove and return item at end of the vector */
int vector_pop(Vector *vector);

/* Remove value at index */
void vector_delete(Vector *vector, int index);

/* Remove all of specified value */
void vector_remove(Vector *vector, int value);

/* Find index of value, -1 if not present */
int vector_find(Vector *vector, int value);