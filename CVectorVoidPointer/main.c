#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "vector.h"

int main () {
  Vector* myVector = create_vector(10);
  assert(myVector != NULL);

  int aNumber = 5005;

  int *anotherNumber = (int*) malloc(sizeof(int));
  *anotherNumber = 1001;

  char *someText = (char*) malloc(3*sizeof(char));
  someText[0] = 'H';
  someText[1] = 'i';
  someText[2] = '\0';

  char **anotherText = (char**) malloc(sizeof(char*));
  *anotherText = (char*) malloc(4*sizeof(char));
  anotherText[0] = 'B';
  anotherText[1] = 'y';
  anotherText[2] = 'e';
  anotherText[3] = '\0';

  assert(set(myVector, 0, (void*)&aNumber) == true);
  assert(set(myVector, 1, (void*)anotherNumber) == true);
  assert(set(myVector, 2, (void*)&someText) == true);
  assert(set(myVector, 3, (void*)anotherText) == true);

  printf("Position %d contains %d", 0, *((int*)get(myVector, 0)) );
  printf("Position %d contains %d", 1, *((int*)get(myVector, 1)) );
  printf("Position %d contains %s", 2, *((char**)get(myVector, 2)) );
  printf("Position %d contains %s", 3, *((char**)get(myVector, 3)) );

  return 0;
}
