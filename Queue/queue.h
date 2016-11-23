typedef struct {
  int *data;
  int size;
  int capacity;
} queue;

// Adds item at end of available storage
void enqueue(queue *, int value);

// Returns value and removes least recently added element
int dequeue(queue *);

// Checks if queue is empty
bool empty(queue *);

// Check is queue is full
bool full(queue *);