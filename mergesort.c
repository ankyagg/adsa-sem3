#include <stdio.h>

void merge(int arr[],int lb, int mid,int ub){
    int temp_size = (ub-lb)+1;
    int i = lb;
    int j = mid+1;
    int k = 0;
    int temp[temp_size];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            i++,k++;
        }
        else{
            temp[k]=arr[j];
            j++,k++;
        }
    }
    while(j<=ub){
        temp[k] = arr[j];
        j++,k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++,k++;
    }
    for(i=0;i<temp_size;i++){
        arr[lb+i]=temp[i];
    }
}

void mergesort(int arr[],int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main(){
    int arr[20],n;
    printf("Enter no. elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i = 0 ; i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int x = 0 ; x<n;x++){
        printf("%d ",arr[x]);
    }
}
