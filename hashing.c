#include <stdio.h>

int linear(int m , int s , int i){
    return (m % s + i)%s;
}

int quadratic (int m , int s, int i){
    return (m % s + i*i)%s;
}

void hashing(int arr[],int m , int s , int choice){
    int a , i=0;
    
    a = m %s;
    if(arr[a]==-1){
        arr[a] = m ;
    }
    else{
        while(i<s){
            if(choice == 1){
                a=linear(m,s,i);
            }
            else{
                a=quadratic(m,s,i);
            }
            if(arr[a]==-1){
                arr[a]=m;
                break;
            }
            i++;
        }
    }
}
int main(){
    int m , s,choice,n;
    printf("Enter size of array: ");
    scanf("%d",&s);
    
    int arr[s];
    for (int i = 0; i < s; i++) {
        arr[i] = -1;
    }
    printf("Choose Probing Method: 1.Linear  2.Quadratic: ");
    scanf("%d", &choice);

    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);
    for(int i = 0 ; i<n ; i++){
        printf("Enter element #%d: ",i+1);
        scanf("%d",&m);
        hashing(arr,m,s,choice);
    }
    for(int i=0 ; i <s;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
