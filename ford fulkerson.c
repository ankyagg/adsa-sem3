#include <stdio.h>

#define MAX 10
#define INF 999

int capacity[MAX][MAX];
int visited[MAX];
int n;

int dfs(int source, int sink , int flow){  
    if(source==sink){
        return flow;
    }
    visited[source]=1;
    for(int i = 0 ; i<n;i++){
        if(!visited[i] && capacity[source][i]>0){
            int curr_flow = dfs(i,sink,flow<capacity[source][i]?flow:capacity[source][i]);
            if(curr_flow>0){
                capacity[source][i] -= curr_flow;
                capacity[i][source] += curr_flow;
                return curr_flow;
            }
        }
    }
    return 0;
}

int ford_fulkerson(int source,int sink){
    int flow,max_flow=0;
    while(1){
        for(int i =0 ; i < n ; i++){
            visited[i]= 0;
        }
        flow= dfs(source,sink,INF);
        if(flow==0){
            break;
        }
        max_flow+=flow;
    }
    return max_flow;
}

int main(){
    int source,sink,max_flow;
    printf("\nEnter the vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(int i =0;i<n;i++){
        printf("---#%d---\n",i+1);
        for(int j =0;j<n;j++){
            scanf("%d",&capacity[i][j]);
        }
    }
    printf("\nEnter the source: ");
    scanf("%d",&source);
    printf("\nEnter the sink: ");
    scanf("%d",&sink);
    max_flow = ford_fulkerson(source,sink);
    printf("%d",max_flow);
}
