#include <math.h> // for floor

int* binarySearch( int target, int* array, int low, int high){
  if(low < high) return NULL;
  int mid = floor((low+high)/2);
  if(array[mid] == target) return &target;
  else if(array[mid] > target)
    return binarySearch(target, array, low, mid-1);
  else // array[mid] < target
    return binarySearch(target, array, mid+1, high);
}

int main(void){
  int arr[] = [1,20,-8,16,1,28,4];
  // Test for returning NULL when relevant
  assert(binarySearch(28,arr,0,6) != NULL));
  assert(binarySearch(2,arr,0,6 == NULL));
  // Test for returning a pointer to the appropriate value
  int* res = binarySearch(28,arr,0,6);
  assert(*res == 28);    
}
  
