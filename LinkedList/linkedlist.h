typedef struct node {
  int value;
  struct node *next;
};

typedef struct {
  struct node *head;
  struct node *tail;
} linkedlist;

// returns number of data elements in list
int size();

// bool returns true if empty
bool isEmpty();

// returns the value of the nth item (starting at 0 for first)
int value_at(int index);

// adds an item to the front of the list
void push_front(int value);

// remove front item and return its value
int pop_front();

// adds an item at the end
void push_back(int value);

// removes end item and returns its value
int pop_back();

// get value of front item
int front();

// get value of an end item
int back();

// insert value at index, so current item at that index is pointed to by new item at index
void insert(int index, int value);

// removes node at given index
void erase(index);

// returns the value of the node at nth position from the end of the list
int value_n_from_end(n);

// reverses the list
void reverse();

// removes the first item in the list with this value
void remove_value(value);