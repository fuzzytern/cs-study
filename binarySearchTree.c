struct bst {
  int value;
  bst* left;
  bst* right;
};
typedef struct bst bst;

bst initBst(int val){
  bst tree = { val, NULL, NULL };
  return tree;
};
void add(int val, bst* tree){
  if(!tree){
    bst t = initBst(val);
    tree = &t;
  }
  else if(val < tree->value)
    add(val, tree->left);
  else
    add(val, tree->right);
};

bst* find(int val, bst* tree){
  if(!tree) return NULL;
  if(val == tree->value) return tree;
  else if(val < tree->value)
    find(val, tree->left);
  else // val > tree->value
    find(val, tree->right);
};


    
