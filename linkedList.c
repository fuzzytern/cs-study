#include <assert.h>

struct node {
  int data;
  node* next;
};
typedef struct node node;

// Allows for chained declaration of lists
// e.g. node* list = link(1,link(2,link(3,NULL)));
node* link(int data, node* next){  
  node list = { data, next };
  return &list;
}
// Puts node elem at the front of the list
void prepend(node* list, node* elem){  
  elem->next = list;
  list = elem;
};

// Returns the numbers of nodes in the list
int length(node* list){
  if(list == NULL)
    return 0;
  return 1 + length(list->next);
}
// Adds elem as the last node of the list
void append(node* list, node* elem){
  if(list == NULL) return;
  if(list->next != NULL)
    append(list->next, elem);
  else
    list->next = elem;
}
int main(void){
  node* list = link(1,link(2,link(3,link(4,link(5,NULL)))));
  prepend(list, 0);
  append(list, 6);
  assert(length(list) == 7); // The list should now have 7 elements
}
