#include <stdio.h>

void main()
{
    char buf[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char *ptr = buf;
    int i = 0;
    printf("Let's raise your ptr!.\n");

    for (i=0; i<6; i++) {
        printf("ptr: 0x%p, *ptr: %c\n", ptr, *ptr);
        ptr++;
    }

    printf("\n Again! let's ptr point to buf.\n");  
    ptr = buf;

    printf("Result of *ptr\n");
    printf("ptr: %p, *ptr:%c\n", ptr, *ptr);

    printf("Result of *ptr++\n");
    printf("ptr: %p, *ptr++:%c\n", ptr, *ptr++);

    printf("Result of *ptr\n");
    printf("ptr: %p, *ptr:%c\n", ptr, *ptr);

    printf("Result of *(ptr++)\n");
    printf("ptr: %p, *(ptr++):%c\n", ptr, *(ptr++));

    printf("Result of *ptr\n");
    printf("ptr: %p, *ptr:%c\n", ptr, *ptr);
    
    printf("Result of *(ptr++) after --ptr.\n");
    --ptr;
    printf("ptr: %p, *(ptr++):%c\n", ptr, *(ptr++));
    
    printf("Result of *ptr\n");
    printf("ptr: %p, *ptr:%c\n", ptr, *ptr);

    printf("Result of *ptr after (*ptr)++\n");
    (*ptr)++;
    printf("ptr: %p, (*ptr)++:%c\n", ptr, *ptr);
    
    printf("Result of *ptr\n");
    printf("ptr: %p, *ptr:%c\n", ptr, *ptr);
    
    printf("Result of *ptr after ptr+=1\n");
    ptr += 1;
    printf("ptr: %p, ptr+=1:%c\n", ptr, *ptr);

    printf("Result of *ptr\n");
    printf("ptr: %p, *ptr:%c\n", ptr, *ptr);

    printf("Result of *ptr after ptr-=2\n");
    ptr -= 2;
    printf("ptr: %p, ptr-=2:%c\n", ptr, *ptr);
    
}