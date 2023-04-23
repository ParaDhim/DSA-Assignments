#include <stdio.h>

int minNo(int *arr,int n){
    int min;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            min = arr[i];
        }
    }
    
    for (int p = 0; p < n; p++)
    {
        // minimum mia
        if ((arr[p]< min) && (arr[p] >= 0))
        {
            min = arr[p];
            // printf("%d ",min);
            // printf("%d\n",min1);
        }
    
    }
    return min;
    
}

int minIndex(int n,int *arr,int nf){
    int minInd;
    for (int i = 0; i < n; i++)
    {
        if ((*(arr+i)) == nf)
        {
            minInd = i;
            break;
        }
        
    }
    return minInd;
    
}

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

    for (int j = 0; j < n; j++)
    {
    scanf("%d",&arr[j]);
    }
    label:
    if (minNo(arr,n) >= 0){
        int min = minNo(arr,n);
        int minInd = minIndex(n,arr,min);
        for (int i = 0; i < n; i++)
        {
        if(arr[i] >= 0)
        {
        for (int i = 0; i < n; i++)
        {  
        arr[i] = arr[i] - (minInd + 1);     
        }
        count += 1;
        goto label;
        }
        }
        printf("%d\n",count);
    }

    
    }
    return 0;
}

