#include <stdio.h>

#define MAX_ELEMENT 100
#define Sentinel 0
#define TRUE 1
#define FALSE 0

int GetIntegerArray(int array[], int max, int sentinel);
int GetInteger(void);
void PrintIntegerArray(int array[], int n);
void ReverseIntegerArray(int array[], int n);
void SwapIntegerElements(int array[], int p1, int p2);

int GetIntegerArray(int array[], int max, int sentinel)
{
    int n, value;
    n = 0;

    while(TRUE) {
        printf("==> ");

        if(value == sentinel)
            break;
        
        if(n == max)
            printf("Overflow!\n");

        array[n] = value;
        n++;
    }

    return n;
}

int GetInteger(void)
{
    int n;
    scanf("%d", &n);
    
    return n;
}

void PrintIntegerArray(int array[], int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d\n", array[i]);
}

void ReverseIntegerArray(int array[], int n)
{
    int i;

    for(i=0; i<n/2; i++)
        SwapIntegerElements(array, i, n-i-1);
}

void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;
    tmp = array[p1];

    array[p1] = array[p2];
    array[p2] = tmp;
}

void main()
{
    int list[MAX_ELEMENT], n;

    printf("Please Input randomly Integer Number.");
    printf("If you input number 0, it will be quit this program.");

    n = GetIntegerArray(list, MAX_ELEMENT, Sentinel);
    ReverseIntegerArray(list, n);
    PrintIntegerArray(list, n);
}
