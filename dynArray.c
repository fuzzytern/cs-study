#include <stdlib.h> // for size_t and assert
#include <stdio.h> // for printf

struct dynArray {
  size_t size;
  size_t capacity;
  int *data;
};
typedef struct dynArray dynArray;

dynArray createDynArray(int* data, size_t size){
  dynArray dArr = { size, size, data };
  return dArr;
}
// returns -1 if it fails, 1 if it successes
char set(dynArray dArr, int it, size_t idx){
  if(idx < 0 || idx > dArr.capacity) // bounds check
    return -1; // Used for handling errors
  dArr.data[idx] = it;
  return 1;
}
// returns a pointer to the found value, NULL if value not found
int* get(dynArray dArr, size_t idx){
  if(idx < 0 || idx > dArr.size) return NULL;
  else
   return &,dArr.data[idx];
}
void push(dynArray* dArr, int it){
  if(dArr->capacity == dArr->size)
    extend(dArr); // allocate more space and copy
  dArr->data[dArray->size] = it;
  dArr->size += 1;
}
void extend(dynArray* dArr){
  dArr->capacity = dArr->size*2; // Just doubling the capacity
  int arr[dArr->capacity]; // C99 Variable-length array, will malloc/free at run time
  for(int i=0; i < dArr->size; i++)
    arr[i] = dArr->data[i];
  free(dArr->data); // free uneeded space from memory
  dArr->data = arr;
}
// returns -1 if failure, 1 if success
char remove(dynArray* dArr, int idx){
  if(idx < 0 || idx > dArr->size)
    return -1;
  else {
    for(int i=idx; i < dArr->size; i++)
      dArr->data[i] = dArr->data[i+1];
    dArr->size -= 1;
    return -1;
  }
}
int main(void){
  int[] items = { 1,2,0,4 };
  dynArray dA = createDynArray(items, sizeof items / sizeof *items);
  set(dA, 3, 2); // Changes 0 to 3
  push(&dA, 5); // Adds 5 to the end of the array.
  for(int i=0; i < dA.size; i++) // should print 1 2 3 4 5
    printf("%d ", *get(dA, i));
  remove(&dA, 1); // removes 2
  assert(dA.size == 3); // The size should now be 3
}
