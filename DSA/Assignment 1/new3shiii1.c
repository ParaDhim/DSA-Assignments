#include <stdio.h>

int minNo(int *arr, int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            min = arr[i];
            break;
        }
    }
    for (int p = 0; p < n; p++)
    {
        // minimum mia
        if ((arr[p] < min) && (arr[p] >= 0))
        {
            min = arr[p];
            // printf("%d ",min);
            // printf("%d\n",min1);
        }
    }
    return min;
}
int minIndex(int n, int *arr, int nf)
{
    int minInd;
    for (int i = 0; i < n; i++)
    {
        if ((*(arr + i)) == nf)
        {
            minInd = i;
            break;
        }
    }
    return minInd;
}
int Check(int *arr,int count,int n)
{
    int minNum = minNo(arr,n);
    int minInd = minIndex(n,arr,minNum);
    // printf("%d %d\n",minNum,minInd);
    for (int k = 0; k < n; k++)
        {
            *(arr + k) = *(arr + k) - (minInd + 1);
        }
        // count += 1;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                flag = 1;
                break;
            }
        minNum = minNo(arr,n);
        minInd = minIndex(n,arr,minNum);
        // printf("%d %d\n",minNum,minInd);
        }
        if (flag == 1)
        {
            if (minNum >= 0)
            {
                return (1 + (Check(arr,count,n)));
            }
        }
        else
        {
            return 1;
        }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, count;
        count = 0;
        scanf("%d", &n);
        int arr[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        printf("%d",Check(arr,count,n));
    }
    return 0;
}
