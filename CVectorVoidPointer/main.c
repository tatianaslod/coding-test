#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "vector.h"

int main () {
  Vector* myVector;
  assert(create_vector(10, &myVector) == NO_ERROR);

  int aNumber = 5005;

  int *anotherNumber = (int*) malloc(sizeof(int));
  *anotherNumber = 1001;

  char *someText = (char*) malloc(3*sizeof(char));
  someText[0] = 'H';
  someText[1] = 'i';
  someText[2] = '\0';

  char **anotherText = (char**) malloc(sizeof(char*));
  *anotherText = (char*) malloc(4*sizeof(char));
  (*anotherText)[0] = 'B';
  (*anotherText)[1] = 'y';
  (*anotherText)[2] = 'e';
  (*anotherText)[3] = '\0';

  assert(set(myVector, 0, (void*)&aNumber) == NO_ERROR);
  assert(set(myVector, 1, (void*)anotherNumber) == NO_ERROR);
  assert(set(myVector, 2, (void*)&someText) == NO_ERROR);
  assert(set(myVector, 3, (void*)anotherText) == NO_ERROR);

  void* element;
  assert(get(myVector, 0, &element) == NO_ERROR);
  printf("Position %d contains %d", 0, *(int*)element);
  assert(get(myVector, 1, &element) == NO_ERROR);
  printf("Position %d contains %d", 1, *(int*)element);
  assert(get(myVector, 2, &element) == NO_ERROR);
  printf("Position %d contains %s", 2, *((char**)element));
  assert(get(myVector, 3, &element) == NO_ERROR);
  printf("Position %d contains %s", 3, *((char**)element));

  return 0;
}
