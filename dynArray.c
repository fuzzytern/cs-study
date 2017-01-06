#include <stdlib.h> // for size_t
#include <stdio.h> // for printf

struct dynArray {
  size_t size;
  size_t capacity;
  int *data;
};
typedef struct dynArray dynArray;

dynArray createDynArray(int *d, size_t s){
  dynArray dArr = { s, 0, d };
  extend(&dArr);
  return dArr;
}
char set(dynArray dArr, int it, size_t idx){
  if(idx > capacity)
    return -1; // Used for handling errors
  dArr.data[idx] = it;
  return 0;
}
int get(dynArray dArr, size_t idx){
  if(dArr.capacity == 0 || idx > dArr.capacity)
   retdArr.data[idx];
}
void push(dynArray *dArr, int it){
  extend(dArr);
  dArr->data[dArray->size] = it;
  dArr->size += 1;
}
void extend(dynArray *dArr){
  if(dArr->capacity <= dArr->size){
    dArr->capacity = dArr->size*2; // Just doubling the capacity
    int arr[dArr->capacity]; // C99 Variable-length array, will malloc/free at run time
    for(int i=0; i < dArr->size; i++)
      arr[i] = dArr->data[i];
    dArr->data = arr;
  };
}
int main(void){
  int[] items = { 1,2,0,4 };
  dynArray dA = createDynArray(items, sizeof items / sizeof *items);
  set(dA, 3, 2); // Changes 0 to 3
  push(&dA, 5); // Adds 5 to the end of the array.
  for(int i=0; i < dA.size; i++) // should print 1 2 3 4 5
    printf("%d ", get(dA, i));
}
