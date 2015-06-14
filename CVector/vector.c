#include "vector.h"

// F: please configure your text editor so the indentation is always done with spaces rather than tabs.

Vector* create_vector(int initial_size){
    int *data = (int *) malloc(initial_size * sizeof(int));
    if (data == NULL) {
        return NULL;
    }
    Vector *vector = (Vector *) malloc(sizeof(Vector));
    vector->size = 0;
    vector->max_size = initial_size;
    vector->data = data;
    return vector;
}

int size(Vector* vector) {
    return vector->size;
}

int get(Vector* vector, int i){
    int *data = vector->data;
    if (i >= vector->max_size || i < 0) {
        return -1;
    }
    return data[i];
}

bool set(Vector* vector, int i, int x) {
    if (i >= vector->max_size) {
        return false;
    }
    if (vector->size * 1.0 / vector->max_size > 0.9) {
        int new_capacity = vector->max_size * 2;
        vector->data = (int *) realloc(vector->data, new_capacity * sizeof(int));
        if (vector->data == NULL) {
            return false;
        }
        vector->max_size = new_capacity;
    }
    vector->data[i] = x;
    vector->size++;
    return true;
}
