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

int main()
{
    int n;
    scanf("%d",&n);
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    int a = 0;
    mergeSort(arr,a,n-1,n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}