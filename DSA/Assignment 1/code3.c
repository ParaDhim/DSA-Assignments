#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void mergesort(int arr[], int lo, int hi)
{
if (lo >= hi) {
return;
}
int mid = (lo + hi) / 2;
mergesort(arr, lo, mid);
mergesort(arr, mid+1, hi);
merge(arr, lo, mid, hi);
}

void merge(int arr[], int lo, int mid, int hi)
{
int i, j, k;
int n_elem_1 = mid - lo + 1;
int n_elem_2 = hi - mid;
int tmp1[n_elem_1 + 1];
int tmp2[n_elem_2 + 1];
for (i = 0; i < n_elem_1; i++) {
tmp1[i] = arr[lo + i];
}
for (j = 0; j < n_elem_2; j++) {
tmp2[j] = arr[mid + 1 + j];
}
tmp1[i] = tmp2[j];
i = j = 0;
for (k = lo; k <= hi; k++) {
if (tmp1[i] <= tmp2[j]) {
arr[k] = tmp1[i]; i += 1;
} else {
arr[k] = tmp2[j]; j += 1;
}
}
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
    int lo = 0;
    int hi = n;
    mergesort(arr,lo, hi);
    int arr1[n][2];
    for (int i = 0; i < n; i++)
    {
        arr1[i][0] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr1[i][1] = i+1;
    }
count = 0;
int sub = 0;
int max = arr1[n-1][0];
int x,y;
    for(int j=0;j<n;j++){
        if(arr1[j][0]-sub>=0 && max>-1){
            x = arr1[j][0] - sub;
            y = x/arr1[j][1];
            y = y + 1;//3
            sub = sub + y*arr1[j][1];
            count += y;
            max = max-sub;
        }
    }
    
    printf("%d\n",count);
    }
    return 0;
}