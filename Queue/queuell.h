typedef struct Node {
  int value;
  struct Node *next;
} node;

typedef struct Queue{
  int *head;
  int size;
} queue;

// adds value at position at tail
void enqueue(queue *q, int value);

// returns value and removes least recently added element (front)
int dequeue(queue *q);

bool empty(queue *q);