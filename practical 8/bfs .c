#include <stdio.h>
int main()
{
    int graph[10][10], visited[10] = {0};
    int queue[10];
    int n, i, j, src;
    int front = 0, rear = -1, current;

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

    visited[src] = 1;
    queue[++rear] = src;

    printf("BFS Traversal: ");

    while(front <= rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for(i = 0; i < n; i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    return 0;
}
