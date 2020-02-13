#include <stdio.h>

void main()
{
    int i = 0;
    char buf[11];

    printf("Please input alpabet as low characters.");
    printf("Input :");

    while(i < 11) {
        scanf("%c", &buf[i]);
        i++;
    }

    printf("You completely inputed 11 letters!, we change it to bigger letters.");

    for (i=0; i<11; i++) {
        printf("%c", buf[i] - ('a' - 'A'));
    }
}