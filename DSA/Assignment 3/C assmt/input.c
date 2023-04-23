#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    char name[2];
    char arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%c", &arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%c", arr[i]);
    }
    scanf("%c", &name[0]);
    printf("%c", name[0]);
    return 0;
}