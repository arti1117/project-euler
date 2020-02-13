#include <stdio.h>

void main()
{
    int i, j;
    int data[][2] = {{10, 20}, {30, 40}, {50, 60}, {70, 80}, {90, 100}};

    int (*ptr)[2];
    int *tptr[5];
    ptr = data;

    for (i=0; i<5; i++) {
        tptr[i] = &data[i][0];
    }

    for (i=0; i<5; i++) {
        printf("ptr: 0x%p, **ptr:%d, *(*ptr + 1):%d\n", ptr, **ptr, *(*ptr + 1));
        ptr++;
    }

    for (i=0; i<5; i++) {
        printf("tptr[%d]: 0x%p, *tptr[%d]: %d, *(tptr[%d]+1): %d\n", i, tptr[i], i, 
        *tptr[i], i, *(tptr[i] + 1));
    }
}