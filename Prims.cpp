#include<bits/stdc++.h>
using namespace std;

#define V 5

int min(int key[], bool mst[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++){
        if (mst[v] == false && key[v] < min){
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    
    int parent[V], key[V];
    bool mst[V];
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V-1; count++) {
        int u = min(key, mst);
        mst[u] = true;
        for (int v = 0; v < V; v++){
            if (graph[u][v] && mst[v] == false && graph[u][v] < key[v]){
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
        
    return 0;
}
