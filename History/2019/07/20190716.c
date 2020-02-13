#include <stdio.h>

void Square(int, int*);

void Square(int lv, int *ret)
{
    if (lv == 2)
        *ret = *ret * *ret;
    else if (lv == 3)
        *ret = *ret * *ret * *ret;
}

void main()
{
    int number, level;

    level = 2;
    number = 3;
    Square(level, &number);
    printf("Level:%d, Return Value:%d\n", level, number);

    level = 3;
    number = 4;
    Square(level, &number);
    printf("Level:%d, Return Value:%d\n", level, number);
}