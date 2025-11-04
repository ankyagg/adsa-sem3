#include <stdio.h>

void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = (lb + ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[],int lb, int mid, int ub){
    int b_size = ub-lb + 1;
    int i = lb;
    int j = mid + 1;
    int k =0;
    int b[b_size];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k] = arr[i];
            i++,k++;
        }
        else{
            b[k] = arr[j];
            j++,k++;
        }
    }
    while(j<=ub){
        b[k] = arr[j];
        j++,k++;
    }
    while(i<=mid){
        b[k] = arr[i];
        i++,k++;
    }
    for(i = 0;i<b_size;i++){
        arr[lb+i] = b[i];
    }
}

int main(){
    int arr[] = {22,4,56,5,78,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    printf("Sorted array: \n");
    for(int x = 0;x<n;x++){
        printf("%d, ",arr[x]);
    }
}
