#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    char arr[8][8];
    for(int i=0;i<8;i++){

    for(int j=0;j<8;j++){

        while ('\n' == (arr[i][j]=getchar() ) );

    }

}
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         scanf("%1c",&arr[i][j]);
    //     }
        
    // }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
        
    }
    // printf("%c",arr[7][7]);
    
    return 0;
}