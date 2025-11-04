#include <stdio.h>


int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start] <= pivot && start<ub){
            start++;
        }
        while(arr[end] >= pivot && end>lb){
            end--;
        }
        if(start<end){
            int temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
    }
    arr[lb] = arr[end];
    arr[end] = pivot;
    return end;
}

void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc = partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int main(){
    int arr[] = {8,4,9,6,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("Sorted array: \n");
    for(int x = 0;x<n;x++){
        printf("%d, ",arr[x]);
    }
}

