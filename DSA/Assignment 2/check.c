#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(int arr[],int low,int mid,int high){
    int i = low;
    int j = low;
    int k = mid + 1;
    int temp[7];
    while ((i <= mid) && (k <= high))
    {
        if (arr[i] <= arr[k])
        {
            temp[j++] = arr[i++];
            // p = p + 1;
        }
        else{
            temp[j++] = arr[k++];
            // p += 1;
        }
        
    }
    while (i <= mid)
    {
        temp[j++] = arr[i++];
    }
    while (k <= high)
    {
        temp[j++] = arr[k++];
    }
    
    for (int item = low; item <= high; item++)
    {
        arr[item] = temp[item];
    }  
}

void mergeSort(int arr[],int low,int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}


int main()
{
    // int n = 7;
    int n;
    scanf("%d",&n);
    int arr[n];
    // int arr[7] = {6,5,9,1,3,8,2};
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int a = 0;
    mergeSort(arr,a,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}