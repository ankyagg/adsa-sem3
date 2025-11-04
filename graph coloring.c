#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4

bool isSafe(int v,int graph[V][V],int color[],int c){
    for(int i = 0; i<V; i++){
        if(graph[v][i] && c == color[i]){
            return false;
        }
    }
    return true;
}

bool graphColoringutil(int graph[V][V],int v , int max_colors , int color[]){
    if(v==V){
        return true;
    }
    for(int c=1;c<=max_colors;c++){
        if(isSafe(v,graph,color,c)){
            color[v] = c;

        if(graphColoringutil(graph,v+1,max_colors,color)==true){
            return true;
        }
        color[v]=0;
        }
    }
    return false;
}

void printsolution(int color[]){
    printf("Solution found");
    for(int i = 0 ; i<V;i++){
        printf("Vertex %d -> Color %d\n",i,color[i]);
    }
}

bool graphcoloring(int graph[V][V],int max_colors){
    int color[V];
    for(int i = 0 ; i<V ; i++){
        color[i]=0;
    }
    if(graphColoringutil(graph,0,max_colors,color)==true){
        printsolution(color);
        return true;
    }
    else{
        printf("NO SOLUTION FOUND!");
        return false;
    }
}

int main(){
    int graph[V][V] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
    };
    int m = 3;
    graphcoloring(graph,3);
    return 0;
}
