#include <stdio.h>

void main(void)
{
    int data = 10;
    int *ptr;

    printf("data's address: 0x%p, data's value: %d\n", &data, data);
    ptr = &data;

    printf("ptr's address: 0x%p, ptr's value: 0x%p\n", &ptr, ptr);

    printf("ptr's pointing value: %d, data's value: %d\n", *ptr, data);
}