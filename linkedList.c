struct node {
  int data;
  node* next;
};
typedef struct node node;

node* link(int data, node* next){  
  node list = { data, next };
  return &list;
};
node prepend(node* list, node* head){  
  head->next = list;
  list = head;
};
int length(node *list){
};
void append(){
};
int main(void){
  node* list = link(1,link(2,link(3,link(4,link(5,NULL)))));
};  
