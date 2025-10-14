#include <stdio.h>

int adj[20][20];
int visited[10];
int n;

void DFS(int v){
    printf("%d    ",v);
    visited[v] = 1;

    for(int i=0; i<n; i++){
        if(adj[v][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

int main(){
    int edges, i, j, v1, v2, start; 

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for(i=0; i<edges; i++){
        for(j=0; j<n; j++){
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges (format: v1 v2): \n");
    for(i=0; i<edges; i++){
        scanf("%d %d", &v1, &v2);

        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }

    for(i=0; i<n; i++){
        visited[i] = 0;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal\n");
    DFS(start);

    return 0;
}


OUTPUT:

Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (format: v1 v2): 
0 1
0 2
1 3
2 4
Enter the starting vertex: 0
DFS Traversal
0    1    3    2    4   