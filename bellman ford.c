#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void bellman_ford(int V,int E, int edges[E][3],int source){
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i] = INF;
    }
    dist[source] = 0;

    for(int i=1; i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u = edges[j][0];  //source vertex
            int v = edges[j][1]; //destination vertex
            int weight = edges[j][2]; //weight of the edge

            //relaxation
            if(dist[u]!=INF && dist[u]+weight < dist[v]){
                dist[v] = dist[u]+weight;
            }
        }
    }
    for(int j=0;j<E;j++){
            int u = edges[j][0];  //source vertex
            int v = edges[j][1];  //destination vertex
            int weight = edges[j][2]; //weight of the edge

            //relaxation
            if(dist[u]!=INF && dist[u]+weight < dist[v]){
                printf("negative weight cycle present");
            }
        }

    //printing of ans
    printf("Shortest path from the source vertex is %d",source);
    printf("\nVertex \t Distance\n");
    for(int i=0;i<V;i++){
        if(dist[i]==INF){
            printf("%d \t INF\n",i);
        }
        else{
            printf("%d \t %d\n",i,dist[i]);
        }
    }
}

int main(){
    int V = 4;
    int E = 5;
    int source = 0;

    // Define the edges: {Source, Destination, Weight}
    int edges[5][3] = {
        {0, 1, 5},  // Path from source
        {0, 2, 4},
        {1, 2, 1},
        {2, 3, 1},
        {3, 1, -3} // Creates the negative cycle
    };

    bellman_ford(V,E,edges,source);
    return 0;
}
