#include "vector.h"

vector_error_type create_vector(int initial_capacity, Vector** vector) {
    void** data = (void**) malloc(initial_capacity * sizeof(void*));
    if (data == NULL) {
        return NO_MEMORY_AVAILABLE;
    }
    *vector = (Vector*) malloc(sizeof(Vector));
    (*vector)->used_size = 0;
    (*vector)->max_capacity = initial_capacity;
    (*vector)->data = data;
    return NO_ERROR;
}

int size(Vector* vector) {
    return vector->used_size;
}

vector_error_type get(Vector* vector, int i, void** element) {
    if (i < 0 || vector->used_size <= i) {
        return INDEX_OUT_OF_BOUNDS;
    }
    *element = vector->data[i];
    return NO_ERROR;
}

double load_factor(Vector* vector) {
    return vector->used_size * 1.0 / vector->max_capacity;
}

vector_error_type set(Vector* vector, int i, void *x) {
    if (i < 0 || i >= vector->max_capacity) {
        return INDEX_OUT_OF_BOUNDS;
    }
    if (load_factor(vector) > 0.9) {
        vector->data = (void**) realloc(vector->data, vector->max_capacity * 2 * sizeof(void*));
        vector->max_capacity *= 2;
    }
    vector->data[i] = x;
    ++vector->used_size;
    return NO_ERROR;
}
