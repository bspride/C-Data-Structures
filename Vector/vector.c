void vector_init(int capacity) {
  int true_capacity = determine_capacity(capacity);
  
  Vector *vector = malloc(size_of(Vector));

  vector->numElements = 0;
  vector->capacity = true_capacity;
  vector->data = (int *)malloc(numElementsof(int) * true_capacity);

  return vector;
}

int vector_numElements(Vector *vector) {
  return vector->numElements;
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

void resize_for_numElements(Vector *vector, int numElements) {
  if(vector->numElements < numElements) {
    while(vector->numElements < numElements) {
      vector->capacity *= 2;
      vector->data = realloc(vector->data, sizeof(int) * vector_capacity(vector));
    }
  } else if(vector->numElements > numElements / SHRINK_FACTOR) {
    vector->capacity /= 2;
    vector->data = realloc(vector->data, sizeof(int)*vector_capacity(vector));
  }
}

int vector_capacity(Vector *vector) {
  return vector->capacity;
}

bool vector_is_empty(Vector *vector) {
  return vector->numElements == 0 ? true : false;
}

int vector_get(Vector *vector, int index) {
  if (index >= vector->numElements || index < 0 ) {
    printf("Index %d out of bounds for vector of numElements %d\n", index, vector->capacity);
    exit(EXIT_FAILURE);
  }
  /* Mem address of start of array plus index of element derefenced will return value */
  return *(vector->data + index);
}

void vector_push(Vector *vector, int value) {
  resize_for_numElements(vector, vector->numElements + 1);

  /* Get pointer to empty space at end of array */
  *(vector->data + vector->numElements) = value;
  /* Increment numElements */
  ++(vector->numElements);
}

void vector_insert(Vector *vector, int index, int value) {
  if (index < 0 ) {
    printf("Index %d out of bounds for vector", index;
    exit(EXIT_FAILURE);
  }
  resize_for_numElements(vector, index + 1);
  *(vector->data + index) = value;
  vector->numElements++;
}

void vector_prepend(Vector *vector, int value) {
  resize_for_numElements(vector, vector->numElements + 1);

  vector_insert(vector, 0, value);
}

int vector_pop(Vector *vector) {
  if(*vector->numElements == 0) {
    exit(EXIT_FAILURE);
  }

  int value = *(vector->data + vector->numElements-1);
  vector->numElements--;

  resize_for_numElements(vector, vector->numElements);
  return value;
}

void vector_delete(Vector *vector, int index) {
  if(index < 0 || index >= vector->numElements) {
    exit(EXIT_FAILURE);
  }

  memmove(vector->data + index, vector->data + index + 1, (vector->numElements-index-1)*sizeof(int));
  vector->numElements--;

  resize_for_numElements(vector, vector->numElements);
}

void vector_remove(Vector *vector, int value) {
  int index = vector_find(vector, value);
  while(index != -1) {
    vector_delete(vector, index);
    index = vector_find(vector, value);
  }
}

int vector_find(Vector *vector, int value) {
  int found_index = -1;
  for(int i = 0; i < vector->numElements; i++) {
    if(*(vector->data + i) == value) {
      found_index = i;
      break;
    }
  }

  return found_index;
}
