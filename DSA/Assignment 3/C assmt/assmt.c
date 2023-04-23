#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    FILE *fp = NULL;
    int count = 0;
    char ch;
    char f1[20];
    char f2[20];
    char arr[20];
    int idx = 0;
    scanf("%s", f1);
    // printf("%s",f1);
    fp = fopen(f1, "r");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    // arr[idx] = fgetc(fp);
    // // printf("%c",fgetc(fp));

    // idx = 1;
    while ((ch = fgetc(fp)) != EOF)
    {
        count += 1;
        if (idx == 0)
        {
            idx += 1;
            // printf("%c", fgetc(fp));
            arr[idx] = fgetc(fp);
        }

        else if (ch != arr[idx])
        {
            idx += 1;
            // printf("%c", fgetc(fp));
            arr[idx] = fgetc(fp);
        }
    }
    rewind(fp);
    // printf("%d",idx);
    // printf("%d",ftell(fp));
    int arr1[idx];
    int idx1 = 0;
    for (int i = 1; i < idx + 1; i++)
    {
        printf("%c", arr[i]);
    }
    // for (int i = 1; i < idx + 1; i++)
    // {
    printf("\n");
    int i = 1;
    int count1 = 0;
label:
    count1 = 0;

    // count1 = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        // printf("%c", ch);
        if (arr[i] == ch)
        {
            // printf("%c", ch);
            // printf("%c", arr[i]);
            count1 += 1;
        }
        if (arr[i] != ch)
        {
            break;
        }
        // if (arr[i] != ch || ch == NULL)
        // {
        //     // printf("%d ",count1);
        //     arr1[idx1] = count1;
        //     count1 = 1;
        //     idx1 += 1;
        // i += 1;
        //     // continue
        //     goto label;
        // }
    }

    // printf("%d ", count1);
    arr1[idx1] = count1;
    // printf("%d",idx);
    // printf("%d ", idx1);
    idx1 += 1;
    if (i < idx)
    {
        // printf("%d ",i);
        i += 1;
        // printf("%d ",i);
        // printf("%d ", count1);
        // fseek(fp, count1, 0);
        goto label;
    }
    // }
    for (int i = 1; i < idx1; i++)
    {
        arr1[i] += 1; 
    }
    for (int i = 0; i < idx1; i++)
    {
        printf("%d ", arr1[i]);
    }
/*Doubt need to be ask that number same numberwould be given uptill frequency or random would be given do mail to them asking the TAs*/
    fclose(fp);
    // merge sort
    
    return 0;
}