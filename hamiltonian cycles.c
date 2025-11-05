#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

bool isSafe(int graph[V][V],int v,int pos,int path[]){
    if(graph[path[pos-1]][v]==0){
        return false;
    }
    for(int i = 0;i<pos;i++ ){
        if(path[i]==v){
            return false;
        }
    }
    return true;
}

void printHam(int path[]){
    for(int i = 0 ; i<V;i++){
        printf("%d-> ",path[i]);
    }
    printf("%d\n",path[0]);
}

bool hamcycleUtil(int graph[V][V],int path[],int pos){
    if(pos==V){
        //checking if last vertex connects to first
        if(graph[path[pos-1]][path[0]]==1){
            return true;
        }
        else{
            return false;
        }
    }
    for(int v=1;v<V;v++){
        if(isSafe(graph,v,pos,path)){
            path[pos]=v;
            if(hamcycleUtil(graph,path,pos+1))
                return true;
            path[pos]=-1;
        }
    }
    return false;
}

bool hamcycle(int graph[V][V]){
    int path[V];
    for(int i =0;i<V;i++){
        path[i]=-1;
    }
    path[0]=0;
    
    if(hamcycleUtil(graph,path,1)==false){
        return false;
    }
    
    printHam(path);
    return true;
}

int main(){
    int graph[V][V];
    int i , j ,input;
    for(i=0;i<V;i++){
        printf("For #%d row",i+1);
        printf("Enter 0/1: ");
        for(j=0;j<V;j++){
            
            scanf("%d",&graph[i][j]);
        }
        printf("\n");
    }
    hamcycle(graph);
}
