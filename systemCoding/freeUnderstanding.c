#include<stdio.h>
#include <malloc.h>
int main() {
    char *a1;
    free(a1);

    char *a2 = NULL;
    free(a2);

    char *a3 = "Hello";
    free(a3);

    char *a4 = (char *) malloc(sizeof(char));
    free(a4);

    return 0;

}
