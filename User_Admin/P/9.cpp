#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------------
Problem Statement:
Optimizing Train Schedules (Flow of Trains)
To optimize train schedules in a metro system, we can represent the system as a directed graph. In this graph:

Nodes represent stations.

Edges represent rail lines connecting two stations, with each edge having a capacity, which indicates the maximum number of trains that can travel along that rail line in a given period (e.g., per hour).

The goal is to determine the maximum number of trains that can flow from a source station (e.g., a central terminal or starting station) to a sink station (e.g., the terminal or endpoint of the metro line), considering the limitations imposed by the capacity of each rail line (edge).

By using the Ford-Fulkerson algorithm, particularly its BFS-based implementation (Edmonds-Karp), we can find the maximum flow from the source to the sink. This will help us optimize the scheduling of trains, ensuring that the system operates at maximum efficiency without exceeding any station’s capacity or any rail line's ability to accommodate trains.

---------------------------------------------------------------
*/

#define V 6 // Number of vertices

// Function to perform BFS and find if there is an augmenting path
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// Main function to compute max flow
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    // Create residual graph and initialize with original capacities
    int rGraph[V][V];
    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[V]; // Store path

    int max_flow = 0; // Final result

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity (bottleneck) of the found path
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities of edges and reverse edges
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}


int main()
{
    int graph[V][V];
    int source = 0;
    int sink = 5;

    cout << "Enter station number initial to final station number along with the max flow of train  (6x6 capacity matrix)\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    int maxFlow = fordFulkerson(graph, source, sink);

    cout << "\nThe maximum possible number of trains that can flow from the source to the sink station is: "  << maxFlow << endl;

    return 0;
}

/*
Station 0 -> Station 1 (capacity = 16 trains per hour)
Station 0 -> Station 2 (capacity = 13 trains per hour)
Station 1 -> Station 2 (capacity = 10 trains per hour)
Station 1 -> Station 3 (capacity = 12 trains per hour)
Station 2 -> Station 3 (capacity = 9 trains per hour)
Station 2 -> Station 4 (capacity = 14 trains per hour)
Station 3 -> Station 5 (capacity = 20 trains per hour)
Station 4 -> Station 5 (capacity = 4 trains per hour)

sample test case:
0 16 13 0 0 0
0 0 10 12 0 0
0 4 0 9 14 0
0 0 0 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0

      0    1    2    3    4    5
  ------------------------------
0 |  0   16   13    0    0    0
1 |  0    0   10   12    0    0
2 |  0    4    0    9   14    0
3 |  0    0    0    0    0   20
4 |  0    0    0    7    0    4
5 |  0    0    0    0    0    0

*/