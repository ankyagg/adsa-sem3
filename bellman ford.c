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
    int V,E,source;
    
    printf("Enter no. of Vertices: ");
    scanf("%d",&V);
    printf("Enter no. of Edges: ");
    scanf("%d",&E);
    
    int edges[E][3];
    for(int i = 0; i<E;i++){
        printf("Enter value of source vertex: ");
        scanf("%d",&edges[i][0]);
        printf("Enter value of destination vertex: ");
        scanf("%d",&edges[i][1]);
        printf("Enter Edge Weight: ");
        scanf("%d",&edges[i][2]);
    }
    
    printf("Enter the source: ");
    scanf("%d",&source);

    bellman_ford(V,E,edges,source);
    return 0;
}
