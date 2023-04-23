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