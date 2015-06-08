#include "vector.h"

double getLoad(Vector* vector);

Vector* create_vector(int initial_size){
	int max_size = 100; //max_size = initial_size
	if (initial_size > max_size) {
		// Porque? saca este if
		return NULL;
	}
	int *data = (int *) malloc(initial_size * sizeof(int));
	// Agrega un checkeo para ver si data es NULL, si lo es, devolve NULL. Malloc puede devolver NULL si es que no hay memoria disponible.
	Vector vector = {initial_size, max_size, data}; // En donde se esta pidiendo esta memoria, que pasa cuando el metodo create_vector hace return?
	Vector *pointer = (Vector *) malloc(1 * sizeof(Vector)); // El 1 es redundante, no se suele poner
	pointer = &vector;  // Si pedis memoria para pointer, y despues la sobreescribis con la posicion de memoria de vector, el valor de pointer se pierde, y causa un leak de memoria, esa memoria que pediste en el malloc nunca va a poder ser utilizada.
	return pointer;
}

int size(Vector* vector) {
	return (*vector).size;
}

int get(Vector* vector, int i){
	int *data = (*vector).data;
	if (i >= (*vector).size || i < 0) { // El checkeo deberia ser contra max_size, que es el tamano maximo del array.
		return -1; // El return value when error se suele documentar en la firma del metodo en el .h
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
