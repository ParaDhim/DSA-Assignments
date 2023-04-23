// C Program to demonstrate fscanf
#include <stdio.h>
 
// Driver Code
int main()
{
    FILE* ptr = fopen("abc.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
 
    /* Assuming that abc.txt has content in below
       format
       NAME    AGE   CITY
       abc     12    hyderabad
       bef     25    delhi
       cce     65    bangalore */
    int buf[100];
    char buf1[100];
    // char buf1[100];
    int i = 0;
    for (int i = 0; i < 3; i++)
    {
        if (fscanf(ptr, "%*s %d", &buf[i]) == 1)
        {
        //    printf("%d\n", buf[i]);
        }
        // if (fscanf(ptr, "%s %*d", &buf1[i]) == 1)
        // {
        //    printf("%s\n", buf[i]);
        // }
        
    }
    rewind(ptr);
    for (int i = 0; i < 3; i++)
    {
        if (fscanf(ptr, "%s %*d", &buf1[i]) == 1)
        {
        //    printf("%c\n", buf1[i]);
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        
           printf("%c %d\n", buf1[i],buf[i]);
        
        
    }

    return 0;
}