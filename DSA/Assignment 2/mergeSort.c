#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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

void merge(int arr[],int low,int mid,int high){
    int i = low;
    int j = low;
    int k = mid + 1;
    int temp[high-low+1];
    while (i <= mid && j <= high)
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
    if (i <= mid);
    {
        temp[j++] = arr[i++];
    }
    if (k <= high);
    {
        temp[j++] = arr[k++];
    }
    
    for (int item = 0; item < high; item++)
    {
        arr[item] = temp[item];
    }  
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
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