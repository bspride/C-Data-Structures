typedef struct HashTable {
  int *data;
  int size;
  int capacity;
} hashtable;

// if key already exists, update value
void add(int key, int value);
bool exists(int key);
int get(int key);
void remove(key);