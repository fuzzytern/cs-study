#include <stdlib.h> // for `NULL`
#include <assert.h> // for `assert`
#include <stdio.h>  // for `printf`

struct node {
  int data;
  struct node *next;
};
typedef struct node node;

// Allows for chained declaration of lists
// e.g. node* list = link(1,link(2,link(3,NULL)));
// This function allocates memory for a new node being created
// This memory will need to be freed by the caller
node* link(int data, node* next){  
  node* ref = malloc(sizeof data + sizeof next);
  ref->data = data;
  ref->next = next;
  return ref;
}

// Returns the numbers of nodes in the list
int length(node* list){
  if(list == NULL)
    return 0;
  return 1 + length(list->next);
}
// Puts node elem at the front of the list
void prepend(node** list, int elem){  
  node* n = link(elem,NULL);
  n->next = *list;
  *list = n;
};
// Adds elem as the last node of the list
void append(node* list, int elem){
  if(list == NULL) return;
  if(list->next != NULL)
    append(list->next, elem);
  else
    list->next = link(elem,NULL);
}
// Gets a node at a specific index
node* getNode(node* list, int idx){
  if(!list) return NULL;
  else {
    node* node = list;
    for(int it = 0; it<idx; it++)
      node = node->next;
    return node;
  }
}

int main(void){
  node* list = link(10,link(20,link(30,link(40,link(50,NULL)))));
  prepend(&list, 0);
  append(list, 60);

  for(int i=0; i<length(list); i++){
    printf("value at index %d: %d\n", i, getNode(list,i)->data);
  }
  assert(length(list) == 7); // The list should now have 7 elements
}
