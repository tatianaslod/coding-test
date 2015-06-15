#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int used_size;
  int max_capacity;
  void **data;
} Vector;

typedef enum {
    NO_ERROR,
    INDEX_OUT_OF_BOUNDS,
    NO_MEMORY_AVAILABLE
} vector_error_type;

// Creates a vector of size initial_size.
vector_error_type create_vector(int initial_capacity, Vector** vector);

// Returns the used size of the vector.
int size(Vector* vector);

// Returns the element in the i position, otherways returns NULL.
vector_error_type get(Vector* vector, int i, void** element);

// Saves x into the i position.
// Pre: i is a valid position in the array.
// Post: if mem cannot be reallocated, retuns false. Otherwise true.
vector_error_type set(Vector* vector, int i, void *x);
