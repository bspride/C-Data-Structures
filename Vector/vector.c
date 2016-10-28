void vector_init(int capacity) {
  int true_capacity = determine_capacity(capacity);
  
  Vector *vector = malloc(size_of(Vector));

  vector->size = 0;
  vector->capacity = true_capacity;
  vector->data = (int *)malloc(sizeof(int) * true_capacity);

  return vector;
}

void resize_for_size(Vector *vector, int size) {
  if(vector->size < size) {
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
  } else if
}

int determine_capacity(int capacity) {
  const int MIN_CAPACITY = 1;
  int true_capacity = VECTOR_INITIAL_CAPACITY;

  if ( capacity < MIN_CAPACITY ) {
    exit(EXIT_FAILURE);
  }

  while(capacity > true_capacity / GROWTH_FACTOR) {
    true_capacity *= GROWTH_FACTOR;
  }

  return true_capacity;
}

int vector_size(Vector *vector) {
  return vector->size;
}

int vector_capacity(Vector *vector) {
  return vector->capacity;
}

bool vector_is_empty(Vector *vector) {
  return vector->size == 0 ? true : false;
}

int vector_get(Vector *vector, int index) {
  if (index >= vector->size || index < 0 ) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->capacity);
    exit(1);
  }
  return vector->data[index];
}

void vector_push(Vector *vector, int value) {
  double_capacity_if_full(vector);

  vector->data[vector->size++] = value;
}

//Need to redo this method
void vector_insert(Vector *vector, int index, int value) {
  if (index >= vector->size || index < 0 ) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->capacity);
    exit(1);
  }
  while(index >= vector->size ) {
    vector_push(vector, 0);
  }
  vector->data[index] = value;
  vector->size++;
}

void vector_prepend(Vector *vector, int value) {
  double_capacity_if_full(vector);

  memmove(vector->data + 1, vector->data, 1);
  vector->data[0] = value;
  vector->size++;
}

int vector_pop(Vector *vector) {
  return vector->data[vector->size--];
}

void vector_delete(Vector *vector, int index) {

}

void vector_remove(Vector *vector, int value) {

}

int vector_find(Vector *vector, int value) {
  
}
