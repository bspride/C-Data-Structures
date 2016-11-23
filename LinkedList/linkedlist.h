typedef struct node {
  int value;
  struct node *next;
} node_t;

typedef struct {
  struct node *head;
  int length;
} linkedlist;

// returns number of data elements in list
int size(linkedlist *);

// bool returns true if empty
bool isEmpty(linkedlist *);

// returns the value of the nth item (starting at 0 for first)
int value_at(linkedlist *, int index);

// adds an item to the front of the list
void push_front(linkedlist *, int value);

// remove front item and return its value
int pop_front(linkedlist *);

// adds an item at the end
void push_back(linkedlist *, int value);

// removes end item and returns its value
int pop_back(linkedlist *);

// get value of front item
int front(linkedlist *);

// get value of an end item
int back(linkedlist *);

// insert value at index, so current item at that index is pointed to by new item at index
void insert(linkedlist *, int index, int value);

// removes node at given index
void erase(linkedlist *, int index);

// returns the value of the node at nth position from the end of the list
int value_n_from_end(linkedlist *, int n);

// reverses the list
void reverse(linkedlist *);

// removes the first item in the list with this value
void remove_value(linkedlist *, int value);