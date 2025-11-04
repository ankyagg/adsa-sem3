#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap_elements(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void printarray(int arr[],int size){
    for(int i = 0; i<size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end){
        while(arr[start]<=pivot && start<ub){
            start++;
        }
        while(arr[end]>=pivot && end>lb){
            end--;
        }
        if(start<end){
            swap_elements(arr,start,end);
        }
    }
    arr[lb] = arr[end];
    arr[end] = pivot;
    return end;
}

int randomizedpartition(int arr[],int lb,int ub){
    int pivot_index = lb + (rand() % (ub-lb+1));
    swap_elements(arr,lb,pivot_index);
    return partition(arr,lb,ub);
}

void randomizedquicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int pivot_index = randomizedpartition(arr,lb,ub);
        randomizedquicksort(arr,lb,pivot_index - 1);
        randomizedquicksort(arr,pivot_index + 1,ub);
    }
}

int main(){
    srand(time(0));
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomizedquicksort(arr, 0, n - 1);
    printarray(arr,n);
    return 0;
}
