#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "vector.h"

int main () {
    Vector* myVector = create_vector(10);
    assert(myVector != NULL);

    assert(set(myVector, 0, 2) == true);
    assert(set(myVector, 1, 3) == true);
    assert(set(myVector, 2, 5) == true);
    assert(set(myVector, 3, 7) == true);

    assert(get(myVector, 3) == 7);
    printf("Position %d contains %d", 3, get(myVector, 3));
    return 0;
}
