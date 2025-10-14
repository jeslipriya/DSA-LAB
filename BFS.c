#include <stdio.h>
#include <stdlib.h>

int queue[10], front = -1, rear = -1, visited[10];

void enqueue(int value) {
    queue[++rear] = value;
}

int dequeue() {
    return queue[++front];
}

void BFS(int graph[10][10], int vertices, int startVertex) {
    int i, currentVertex;

    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    int graph[10][10] = {0};
    int u, v, i, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) where 0-based index:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(graph, vertices, startVertex);

    return 0;
}


OUTPUT:

Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (u v) where 0-based index:
0 1
0 2
1 3
2 4
Enter the starting vertex: 0

BFS Traversal: 0 1 2 3 4 