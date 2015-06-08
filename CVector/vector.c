#include "vector.h"

double getLoad(Vector* vector);

Vector* create_vector(int initial_size){
	int max_size = 100;
	if (initial_size > max_size) {
		return NULL;
	}
	int *data = (int *) malloc(initial_size * sizeof(int));
	Vector vector = {initial_size, max_size, data};
	Vector *pointer = (Vector *) malloc(1 * sizeof(Vector));
	pointer = &vector;
	return pointer;
}

int size(Vector* vector) {
	return (*vector).size;
}

int get(Vector* vector, int i){
	int *data = (*vector).data;
	if (i >= (*vector).size || i < 0) {
		return -1;
	}
    return data[i];
}

bool set(Vector* vector, int i, int x){
	if (((*vector).size + 1) >= (*vector).max_size) {
	    return false;
	}
	//load of array
	
	if (getLoad(vector) > 0.9) { //it works without the if :(
		// Vector *newVector = create_vector((*vector).size * 2);
		// if (newVector == NULL) {
		// 	return false;
		// }
		//(*newVector).data = (*vector).data;
		// free(vector);
		// vector = newVector; 
	}
    for (int j = (*vector).size - 1; j > i + 1; j--) {
		int tmp = (*vector).data[j];
		(*vector).data[j] = (*vector).data[j-1];
		(*vector).data[j-1] = tmp;
	}
	(*vector).data[i] = x;
    return true;
}

double getLoad(Vector* vector) {
	int elements_with_value_count = 0;
	for (int j = 0; j < (*vector).size; j++) {
		if ((*vector).data[j] != 0) {
			elements_with_value_count++;
		}
	}
	return elements_with_value_count / (*vector).size;
}