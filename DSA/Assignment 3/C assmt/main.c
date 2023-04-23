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
