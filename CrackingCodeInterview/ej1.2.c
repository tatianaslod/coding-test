//rm -f a.out && gcc ej1.2.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
// char ** en parameter return
// [] por *(puntero+x)
void scopy(char *input, char **retCopy) {
    int i = 0;
    while (input[i] != '\0') {
        i++;
    }
    int size = i + 1;
    char *s = (char*)malloc(size * sizeof(char));
    i = 0;
    while (i < size) {
        s[i] = input[i];
        ++i;
    }
    *retCopy = s;
    printf("a:%p\n", retCopy);
    printf("b:%s\n", *retCopy);
    printf("c:%c\n", **retCopy);
    //printf("1:%s\n", *retCopy);
}

int main() {
    char *c = (char*) malloc(4 * sizeof(char));
    char **copy = (char**) malloc(sizeof(char*));
    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = '\0';
    scopy(c, copy);
    printf("2:%s\n", *copy);

    free(c);
    return 0;
}
