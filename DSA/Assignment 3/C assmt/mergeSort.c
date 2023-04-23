#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void merge(int arr[],char arr1[],int low,int mid,int high,int n){
    int i,j,k;
    i = low;
    j = low;
    k = mid+1;
    int temp[n];
    char temp1[n];
    
    while (i <= mid && k <= high)
    {
        if (arr[i] < arr[k])
        {
            temp[j] = arr[i];
            temp1[j] = arr1[i+1];
            i++;
            j++;
        }
        else
        {
            temp[j] = arr[k];
            temp1[j] = arr1[k+1];
            k++;
            j++;
        }
        
    }
    while (i <= mid)
    {
        temp[j] = arr[i];
        temp1[j] = arr1[i+1];
        i++;
        j++;
    }
    while (k <= high)
    {
        temp[j] = arr[k];
        temp1[j] = arr1[k+1];
        k++;
        j++;
    }

    for (int l = low; l <= high; l++)
    {
        arr[l] = temp[l];
        arr1[l+1] = temp1[l];
    }
    
    
    
    
    
}

void mergesort(int arr[],char arr1[],int low,int high,int n)
{
    if (low>=high)
    {
        return;
    }
    int mid = (low + high)/2;
    mergesort(arr,arr1,low,mid,n);
    mergesort(arr,arr1,mid+1,high,n);
    merge(arr,arr1,low,mid,high,n);
    
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    char arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%s",arr1);
    int low = 0;
    int high = n-1;
    mergesort(arr,arr1,low,high,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c",arr1[i]);
    }
    return 0;
}