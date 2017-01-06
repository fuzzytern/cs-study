#include <assert.h>

struct bst {
  int value;
  bst* left;
  bst* right;
};
typedef struct bst bst;

bst initBst(int val){
  bst tree = { val, NULL, NULL };
  return tree;
}
void add(int val, bst* tree){
  if(!tree){
    bst t = initBst(val);
    tree = &t;
  }
  else if(val < tree->value)
    add(val, tree->left);
  else
    add(val, tree->right);
}
bst* find(int val, bst* tree){
  if(!tree) return NULL;
  if(val == tree->value) return tree;
  else if(val < tree->value)
    find(val, tree->left);
  else // val > tree->value
    find(val, tree->right);
}
void remove(int val, bst* tree){
  bst* node = find(val, tree);
  if(!node) return;
  if(node->left && !node->right)
    node = node->left;
  else if(node->right && !node->left)
    node = node->right;
  else { // node->left && node->right
    bst* smallest = smallestChild(node->right);
    node->value = smallest->value;
    remove(smallest->value, smallest);
  }
}
bst* smallestChild(bst* node){
  if(!node->left) return node;
  else
    smallestChild(node->left);
}
int main(void){
  bst* tree = initBst(5);
  add(2,tree);
  add(7,tree);
  add(-2,tree);
  add(3,tree);
  add(19,tree);
  add(10,tree);
  remove(10,tree);
  bst* leaf = find(19, tree);
  assert(!leaf->left && !leaf->right);
  remove(2,tree);
  assert(tree->value == 3);
}
    
