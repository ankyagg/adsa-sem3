#include <stdio.h>
#include <stdbool.h>

#define V 4

bool isSafe(int v , int graph[V][V],int path[],int pos){
    if(graph[path[pos-1]][v]==0){
        return false;
    }
    for(int i =0;i<pos;i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;
}

void printHam(int path[]){
    printf("Path: ");
    for(int i = 0; i<V; i++){
        printf("%d -> ", path[i]);
    }
    printf("%d",path[0]);
}

bool hamcycleUtil(int path[],int pos,int graph[V][V]){
    if(pos==V){
        if(graph[path[pos-1]][path[0]]==1){
            return true;
        }
        else{
            return false;
        }
    }


    for(int v=1;v<V;v++){
        if(isSafe(v,graph,path,pos)){
            path[pos]=v;

            if(hamcycleUtil(path,pos+1,graph)==true){
                return true;
            }
            path[pos]=-1;
        }
    }
    return false;
}

bool hamcycle(int graph[V][V]){
    int path[V];
    for(int i =0; i<V;i++){
        path[i]=-1;
    }
    path[0]=0;
    printHam(path);
    return true;
}

int main(){
    int graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0},
    };
    hamcycle(graph);
    return 0;
}
