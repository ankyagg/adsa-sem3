#include <stdio.h>
#include <stdlib.h>

#define INF 9999

int min(int a , int b){
    return (a<b)? a : b;
}

void floydwarshall(int graph[4][4],int V){
    int dist[V][V];
    int i , j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    //printing of the final answer
    printf("Shortest distance between all pairs of vertices: %d",V);
    printf("\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(dist[i][j]==INF){
                printf("%8s","INF");
            }
            else{
                printf("%8d",dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int V = 4;
    int graph[4][4]={
    {0,5,INF,10},
    {INF,0,3,INF},
    {INF,INF,0,1},
    {INF,INF,INF,0}
    };
    floydwarshall(graph,V);

    return 0;
};


