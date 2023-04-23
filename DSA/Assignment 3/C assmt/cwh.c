#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    FILE *ptr = NULL;
    ptr = fopen("myfile.txt", "a+");
    // ptr = fopen("myfile.txt", "r+");// r+ write the content to the fiel at the beginning without deleting the rest of the other content
    // ptr = fopen("myfile.txt", "w");
    // ptr = fopen("myfile.txt", "r");
    // char * c = fgetc(ptr);
    // printf("The character I read was %c\n", c);
    // c = fgetc(ptr);
    // printf("The character I read was %c\n", c);



    // char str[4];
    // fgets(str,8,ptr);
    // printf("The string is %s",str);


    fputc('o',ptr);
    fputs("paras is the best",ptr);
    // fputs("paras is the best",ptr);

    return 0;
}