#include <bits/stdc++.h>
using namespace std;

/*
- works only for Directed Acyclic Graph (DAG)
A topological ordering is an ordering of the nodes in a directed graph 
where for each directed edge from node A to node B, node A appears 
before node B in the ordering.

Pick an unvisited node beginning with the selected nodes, do DFS exploring
only unvisited nodes, on recursive callback of dfs add current node to the 
topological ordering in reverse direction
time: O(V+E)
*/

class Graph{
    int n;
    list<int> *adj;
public: 
    Graph(int n){
        this->n = n;
        adj = new list<int>[n+1];
    }
    void addEdge(int x, int y){
        adj[x].push_back(y);
    }

    int dfs(int i, int at, vector<bool>&visited, vector<int>&ordering){
        visited[at] = true;
        for(auto edge : adj[at]){
            if(!visited[edge]) 
                i = dfs(i, edge, visited, ordering );
        }
        ordering[i] = at;
        // ordering.insert(ordering.begin(), at);
        return --i;
    }

    void topoSort(){
        vector<bool>visited(n+1, false);       
        vector<int>ordering(n+1, -1);      // stores the topological ordering of nodes
        int i = n;          // iterator to store topological sort in reverse direction

        for(int src=1; src<=n; src++){
            if(!visited[src]){
                i = dfs(i, src, visited, ordering);
            }
        }
        for(auto itr : ordering){
            cout << itr << " ";
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.topoSort();
    return 0;
}

//OUTPUT: -1 3 1 4 2 5 