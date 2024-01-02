#include <stdio.h>
void dijkstra(int n, int v, int cost[10][10], int dist[10], int prevNode[10])
{
    int count, u, i, w, visited[10], min;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = 999;
        prevNode[i] = -1;
        if (cost[v][i] < 999)
        {

            prevNode[i] = v;
            dist[i] = cost[v][i];
        }
    }

    visited[v] = 1;
    dist[v] = 1;
    prevNode[v] = v;
    count = 2;

    while (count <= n)
    {
        min = 999;
        for (w = 0; w < n; w++)
            if ((dist[w] <= min) && (visited[w] != 1))
            {
                min = dist[w];
                u = w;
            }

        visited[u] = 1;
        count++;
        
        for (w = 0; w < n; w++)
            if ((dist[u] + cost[u][w] < dist[w]) &&
                (visited[w] != 1))
            {
                dist[w] = dist[u] + cost[u][w];
                prevNode[w] = u;
            }
    }
}

void main()
{
    int n, v, cost[10][10], dist[10], prevNode[10], i, j;

    printf("Enter number of vertices:");
    scanf("%d", &n);

    printf("\nEnter cost matrix (for infinity, enter 999):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("\nEnter source vertex:");
    scanf("%d", &v);

    dijkstra(n, v, cost, dist, prevNode);

    printf("\nShortest path from \n");
    for (i = 0; i < n; i++)
        if (i != v)
            printf("\n%d -> %d = %d; prev node = %d", v, i, dist[i], prevNode[i]);
            
    printf("\n");
}
