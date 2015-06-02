#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int size;
  int max_size;
  int *data;
} Vector;

// Creates a vector of size initial_size.
Vector* create_vector(int initial_size);

// Returns the max size of the vector.
int size(Vector* vector);

// Returns the element in the i position.
int get(Vector* vector, int i);

// Saves x into the i position.
// Pre: i is a valid position in the array.
// Post: if mem cannot be reallocated, retuns false. Otherwise true.
bool set(Vector* vector, int i, int x);
