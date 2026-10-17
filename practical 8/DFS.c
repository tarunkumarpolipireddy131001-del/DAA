#include <stdio.h>
int graph[10][10];
int visited[10] = {0};
int n;

void DFS(int current)
{
    int i;

    visited[current] = 1;
    printf("%d ", current);

    for(i = 0; i < n; i++)
    {
        if(graph[current][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    printf("DFS Traversal: ");
    DFS(src);

    return 0;
}

