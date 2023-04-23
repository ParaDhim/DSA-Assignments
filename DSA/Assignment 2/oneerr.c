#include <stdio.h>
int main()
{
    int n = 6,m = 5;
    // scanf("%d %d",&n,&m);
    int arr[5] = {1,2,3,4,4};
    int arr1[5] = {2,3,4,5,1};
    // long long int arr[n];
    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%lld %lld",&arr[i],&arr1[i]);
    // }
    // int a = 0;
    // mergeSort(arr,arr1,a,m-1,m);
    
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d \n",arr1[i]);
    // }

    int count = 0;
    int i = 1;
    label:
    while(i <= n)
    {
        int p = count;
        if (i == arr[count])
        {
            for (int j = p; j <m; j++)
        {
            if(i == arr[j])
            {
                printf("%d ",arr1[j]);
                
            }
            else
            {
                count = j;
                // printf("count: %d\n",count);
                // printf("i==%d\n",i);
                i = i + 1;
                printf("\n");
                goto label;
            }
            
        }
        printf("\n");
        }
        else
        {
            int a = -1;
            i = i + 1;
            printf("`%d",a);
        }
    i = i + 1;  
    }
    
    return 0;
}