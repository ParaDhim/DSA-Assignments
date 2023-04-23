#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
    int n,count;
    count = 0;
    scanf("%d",&n);
    int arr[n];
    // scanf("%d ",arr);
    for (int j = 0; j < n; j++)
    {
    scanf("%d",&arr[j]);
    }

    int min;
    int min1;
    
    label:
    min = arr[0];
    for (int p = 0; p < n; p++)
    {
        // minimum mia
        if ((arr[p]<= min) && (arr[p] >= 0))
        {
            min = arr[p];
            min1 = p;
            // printf("%d ",min);
            // printf("%d\n",min1);
        }
    
    }
for (int k = 0; k < n; k++)
{
    if(arr[k]>=0){
    for (int i = 0; i < n; i++)
    {  
        arr[i] = arr[i] - (min1 + 1);
        // printf("%d\n",arr[i]);
    }
    count += 1;
    // printf("%d\n",count);
    goto label;
    }
}
    
    
    printf("%d\n",count);
    }
    return 0;
}