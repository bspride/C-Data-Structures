#include "linkedlist.h"

void linkedlist_init(linkedlist *ll) {
  ll->head = null;
  ll->tail = null;
  ll->length = 0;
}

// returns number of data elements in list
int size(linkedlist *ll) {
  return ll->length;
}

// bool returns true if empty
bool isEmpty(linkedlist *ll) {
  return ll->length == 0;
}

// returns the value of the nth item (starting at 0 for first)
int value_at(linkedlist *ll, int index) {
  node_t *current;

  if(ll->head != NULL) {
    current = ll->head;

    for(int i = 0; i < index; i++) {
      current = current->next;
    }

    if(current != NULL) {
      return current->value;
    }
  }

  exit(EXIT_FAILURE);
}

// adds an item to the front of the list
void push_front(linkedlist *ll, int value) {
  node_t *current;

  node_t *insert = malloc(size_of(node_t));
  insert->value = value;

  if(ll->head == NULL) {
    ll->head = insert;
  } else {
    current = ll->head;
    ll->head = insert;
    insert->next = current;
  }

  ll->length++;
}

// remove front item and return its value
int pop_front(linkedlist *ll) {
  node_t *current;
  if(ll->head == NULL) {
    exit(EXIT_FAILURE);
  } else {
    current = ll->head;
    ll->head = current->next;
    ll->length--;
  }

  int value = current->value;
  free(current);

  return value;
}

// adds an item at the end
void push_back(linkedlist *ll, int value) {
  node_t *current;
  node_t *insert = malloc(size_of(node_t));
  insert->value = value;

  if(ll->head == NULL) {
    ll->head = insert;
  } else {
    current = ll->head;
    while(current->next != null) {
      current = current->next;
    }
    current->next = insert;
  }

  ll->length++;
}

// removes end item and returns its value
int pop_back(linkedlist *ll) {
  node_t *current;

  if(ll->head == NULL) {
    exit(EXIT_FAILURE);
  } else if(ll->length == 1){
    current = ll->head;
    ll->head = null;
  } else {
    current = ll->head;
    while(current->next != NULL) {
      current = current->next;
    }
  }
  int value = current->value;

  free(current);

  return value;
}

// get value of front item
int front(linkedlist *ll) {
  if(ll->head == NULL) {
    return -1;
  }
}

// get value of an end item
int back(linkedlist *ll);

// insert value at index, so current item at that index is pointed to by new item at index
void insert(linkedlist *ll, int index, int value);

// removes node at given index
void erase(linkedlist *ll, int index);

// returns the value of the node at nth position from the end of the list
int value_n_from_end(linkedlist *ll, int n);

// reverses the list
void reverse(linkedlist *ll);

// removes the first item in the list with this value
void remove_value(linkedlist *ll, int value);