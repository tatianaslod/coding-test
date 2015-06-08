#include "vector.h"
#include <stdio.h>  // F: do you need stdio.h?

// F: please configure your text editor so the indentation is always done with spaces rather than tabs.
// F: -> is a shortcut for (* ).

Vector* create_vector(int initial_size){
	int *data = (int *) malloc(initial_size * sizeof(int));
	if (data == NULL) {
		return NULL;
	}
	Vector *vector = (Vector *) malloc(sizeof(Vector));
	(*vector).size = 0;  // F: vector->size
	(*vector).max_size = initial_size;  // F: ->
	(*vector).data = data;  // F: ->
	return vector;
}

int size(Vector* vector) {
	return (*vector).size;  // F: return vector->size;
}

int get(Vector* vector, int i){
	int *data = (*vector).data;
	if (i >= (*vector).max_size || i < 0) {  // F: ditto. How about if the element is not set? How can we handle that case?
		return -1;
	}
	return data[i];
}

bool set(Vector* vector, int i, int x){  // F: space between ) and {
    // F: what happens if i > max_size? We should handle that somehow, maybe returning false, or maybe resizing the vector, what do you think?
	if (((*vector).size * 1.0 / (*vector).max_size) > 0.9) { // ->
		int new_capacity = (*vector).max_size * 2;
		(*vector).data = (int *) realloc((*vector).data, new_capacity * sizeof(int));  // ->
		if ((*vector).data == NULL) {
			return false;
		}
		(*vector).max_size = new_capacity;  // ->
	}
	(*vector).data[i] = x;  // ->
    // F: as a side note, a[b] is a shortcut for (a+b)*. This means, given the memmory addres a, go forward b spaces, and then give me the content. It's fine to use [], I jsut wanted to point that out.
	(*vector).size++;  // ->
	return true;
}

// F: always ensure a \n before EOF.

