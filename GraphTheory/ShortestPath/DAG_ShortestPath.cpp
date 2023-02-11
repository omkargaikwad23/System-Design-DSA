#include <bits/stdc++.h>
using namespace std;

/*
- works only for Directed Acyclic Graph (DAG)
Single Source Shortest Path
time: O(V+E)
*/

class Graph{
    int n;
    list<pair<int, int>> *adj;
public: 
    Graph(int n){
        this->n = n;
        adj = new list<pair<int, int>>[n+1];
    }
    void addEdge(int x, int y, int w){
        adj[x].push_back({y, w});
    }

    int dfs(int i, int at, vector<bool>&visited, vector<int>&ordering){
        visited[at] = true;
        for(auto edge : adj[at]){
            if(visited[edge.first]) continue;
            i = dfs(i, edge.first, visited, ordering );
        }
        ordering[i] = at;
        // ordering.insert(ordering.begin(), at);
        return --i;
    }

    vector<int> topoSort(){
        vector<bool>visited(n+1, false);       
        vector<int>ordering(n+1, -1);      // stores the topological ordering of nodes
        int i = n;          // iterator to store topological sort in reverse direction

        for(int src=1; src<=n; src++){
            if(!visited[src]){
                i = dfs(i, src, visited, ordering);
            }
        }
        
        return ordering;
    }

    void dagShortestPath(vector<int> &ordering, int start, int numNodes){
        vector<int>dist(n+1, INT_MAX);
        dist[start] = 0;

        for(int i=1; i<=numNodes; i++){
            int nodeIndex = ordering[i];
            
            for(auto edge : adj[nodeIndex]){
                int newDist = dist[nodeIndex] + edge.second;

                if(dist[edge.first]==INT_MAX) 
                    dist[edge.first] = newDist;
                else 
                    dist[edge.first] = min(dist[edge.first], newDist);
            }
        }
        cout << "Shortest paths of all nodes from node 1\n";
        for(int i=1; i<=n; i++){
            cout << i << " -> " << dist[i] << "\n";
        }
    }
};

int main()
{
    
    Graph g(8);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 8);
    g.addEdge(3, 7, 11);
    g.addEdge(4, 5, -4);
    g.addEdge(4, 6, 5);
    g.addEdge(4, 7, 2);
    g.addEdge(5, 8, 9);
    g.addEdge(6, 8, 1);
    g.addEdge(7, 8, 2);

    cout << "Topological ordering of nodes in grpah :\n";
    vector<int> topSortOrdering = g.topoSort();
    for(auto o : topSortOrdering){
        cout << o << " ";
    }
    cout << "\n";

    cout << "Consider starting node as " << 1 << "\n";

    g.dagShortestPath(topSortOrdering, 1, 8);


    return 0;
}

/*
Topological ordering of nodes in grpah :
-1 1 2 3 4 7 6 5 8
Consider starting node as 1
Shortest paths of all nodes from node 1 
1 -> 0
2 -> 3
3 -> 6
4 -> 7
5 -> 3
6 -> 12
7 -> 9
8 -> 11
*/