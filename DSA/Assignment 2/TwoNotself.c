#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(long long int arr[],int low,int mid,int high,int n){
    int i,j,k;
    int size = high - low + 1;
    long long int temp[n];
    i = low;
    j = low;
    k = mid + 1;
    while ((i <= mid) && (k <= high))
    {
        if (arr[i] <= arr[k])
        {
            temp[j] = arr[i];
            i += 1;
            j += 1; 
        }
        else
        {
            temp[j] = arr[k];
            k += 1;
            j += 1;
            
        }
    }
    while(i <= mid){
        temp[j] = arr[i];
        j += 1;
        i += 1;
    }
    while(k <= high){
        temp[j] = arr[k];
        j += 1;
        k += 1;
    }
        
    for (int item = low; item <= high; item++)
    {
        arr[item] = temp[item];
    }
      
}
    
void mergeSort(long long int arr[],int low,int high,int n)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr,low,mid,n);
    mergeSort(arr,mid + 1,high,n);
    merge(arr,low,mid,high,n);
    
}

void PosKnife(long long int arr[],int n,int h)
{


    if (n >= h)
    {
        printf("1");
        return;
    }
    else
    {
        int initialise = 1;
        int health2 = h;
        int arithOperat = 0;

        int temp[n];
        for (int j = 0; j < n-1; j++)
        {
            temp[j] = arr[j+1] - arr[j];
        }

        while (initialise <= health2)
        {
            int arithOperat = (initialise + health2)/2;
            int CopyArithOperat = arithOperat;
            for (int k = 0; k < n-1; k++)
            {
                int delta = temp[k];
                if (delta < arithOperat){
                    CopyArithOperat += delta;
                }
                else{
                    CopyArithOperat += arithOperat;
                }
            }
            if (CopyArithOperat < h){
                initialise = arithOperat + 1;
            }
            else{
                health2 = arithOperat - 1;
            }
            
        }
        printf("%d\n",health2+1);
        
         
    }
}


int main()
{
    int cases;
    scanf("%d",&cases);
    for (int i = 0; i < cases; i++)
    {
        int n,h;
        scanf("%d %d",&n,&h);
        long long int arr[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%lld",&arr[j]);
        }
        int a = 0;
        mergeSort(arr,a,n-1,n);
            

        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d ",arr[j]);
        // }
        PosKnife(arr,n,h);
    }
    return 0;
}
