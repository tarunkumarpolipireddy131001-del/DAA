
#include <stdio.h>

int main()
{
    int n, e, i, j, u, v, weight;
    int edges[20][3], graph[20];
    int mst[20][3], cost = 0, count = 0, temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for(i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i][0],
              &edges[i][1], &edges[i][2]);

    for(i = 0; i < e - 1; i++)
    {
        for(j = 0; j < e - i - 1; j++)
        {
            if(edges[j][2] > edges[j + 1][2])
            {
                for(int k = 0; k < 3; k++)
                {
                    temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }

    for(i = 0; i < n; i++)
        graph[i] = i;

    printf("Edges in MST:\n");

    for(i = 0; i < e; i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        weight = edges[i][2];

        while(graph[u] != u)
            u = graph[u];

        while(graph[v] != v)
            v = graph[v];

        if(u != v)
        {
            mst[count][0] = edges[i][0];
            mst[count][1] = edges[i][1];
            mst[count][2] = weight;

            printf("%d - %d : %d\n",
                   edges[i][0], edges[i][1], weight);

            cost += weight;
            graph[u] = v;
            count++;
        }

        if(count == n - 1)
            break;
    }

    printf("Minimum cost = %d\n", cost);

    return 0;
}
