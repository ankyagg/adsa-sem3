#include <stdio.h>
#include <stdbool.h>

#define MAX 50
int subset_solution[MAX];

void display_Subset(int subSet[],int size){
    printf("{");
    for(int i = 0; i<size ; i++){
        printf("%d ",subSet[i]);
    }
    printf("}\n");
}

void subsetSum(int set[],int n, int subSize,int total,int k,int target_sum){
    if(total == target_sum){
        display_Subset(subset_solution,subSize);

    if(k<n){
        subsetSum(set,n,subSize-1,total-set[k-1],k,target_sum);
    }
    }
    for(int i = k ; i<n;i++){
        if(total + set[i]<=target_sum){
            subset_solution[subSize] = set[i];
            subsetSum(set,n,subSize+1,total + set[i],i+1,target_sum);
        }
    }
}

void findSubset(int set[],int n , int target_sum){
    subsetSum(set,n , 0 ,0,0,target_sum);
}

int main(){
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set)/sizeof(set[0]);
    int target_sum = 35;
    findSubset(set,n,target_sum);
    return 0;
}
