#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// #include <time.h>

// #include <unistd.h>
void merge(long long int arr[],long long int arr1[],int low,int mid,int high,int n){
    int i,j,k;
    int size = high - low + 1;
    long long int temp[n];
    i = low;
    j = low;
    k = mid + 1;
    long long int temp1[n];
    while ((i <= mid) && (k <= high))
    {
        if (arr[i] <= arr[k])
        {
            temp[j] = arr[i];
            temp1[j] = arr1[i];
            i += 1;
            j += 1; 
        }
        else
        {
            temp[j] = arr[k];
            temp1[j] = arr1[k];
            k += 1;
            j += 1;
            
        }
    }
    while(i <= mid){
        temp[j] = arr[i];
        temp1[j] = arr1[i];
        j += 1;
        i += 1;
    }
    while(k <= high){
        temp[j] = arr[k];
        temp1[j] = arr1[k];
        j += 1;
        k += 1;
    }
        
    for (int item = low; item <= high; item++)
    {
        arr[item] = temp[item];
        arr1[item] = temp1[item];
    }
      
}
    


void mergeSort(long long int arr[],long long int arr1[],int low,int high,int n)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr,arr1,low,mid,n);
    mergeSort(arr,arr1,mid + 1,high,n);
    merge(arr,arr1,low,mid,high,n);
    
}

int main()
{
    // double time_spent = 0.0;
 
    // clock_t begin = clock();
    int n,m;
    scanf("%d %d",&n,&m);
    long long arr[m];
    long long arr1[m];
    // long long int arr[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld",&arr[i],&arr1[i]);
    }
    int a = 0;
    mergeSort(arr,arr1,a,m-1,m);
    
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
            for (int j = p; j <=m; j++)
            {
                if(i == arr[j])
                {
                    printf("%lld ",arr1[j]);
                    
                }
                else
                {
                    count = j;
                    // printf("count: %d\n",count);
                    // printf("i==%d\n",i);
                    i = i + 1;
                    printf("\n");
                    goto label;
                    // break;
                }
                
            }
            
        }
        else
        {
            int a = -1;
            i = i + 1;
            printf("%d\n",a);
        }
        // printf("\n");
    // i = i + 1;  
    }
    // clock_t end = clock();
    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    // printf("The elapsed time is %f seconds", time_spent);
    return 0;
}