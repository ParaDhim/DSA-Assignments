#include <stdio.h>
void merge(int arr1[],int arr2[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1 ,n2=right-mid;
    int A[n1],B[n2],C[n1],D[n2];
    for(i=0;i<n1;i++){
        A[i]=arr1[left+i];
        C[i]=arr2[left+i];
    }
    for(j=0;j<n2;j++){
        B[j]=arr1[mid+1+j];
        D[j]=arr2[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(A[i]<B[j]){
            arr1[k]=A[i];
            arr2[k]=C[i];
            i++;
        }
        else{
            arr1[k]=B[j];
            arr2[k]=D[j];
            j++;
        }
        k++;
    }
    	while (i < n1) {
		arr1[k] = A[i];
        arr2[k] = C[i];
		i++;
		k++;
        
	}
	while (j < n2) {
		arr1[k] = B[j];
        arr2[k] = D[j];
		j++;
		k++;
	}
}
void mergesort(int arr1[],int arr2[],int left,int right){
    int mid=(left+right)/2;
    if(left>=right){
        return;
    }
    mergesort(arr1,arr2,left,mid);
    mergesort(arr1,arr2,mid+1,right);
    merge(arr1,arr2,left,mid,right);
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[m];
    int arr1[m];
    // long long int arr[n];
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld",&arr[i],&arr1[i]);
    }
    int a = 0;
    mergesort(arr,arr1,a,m-1);
    
    for (int i = 0; i < m; i++)
    {
        printf("\n%d ",arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d \n",arr1[i]);
    }

return 0;

}