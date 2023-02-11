#include <bits/stdc++.h>
using namespace std;


/*
Kosaruju algorithm used to find Strongly connected components in a graph

A directed graph is called strongly connected if there is a path in each 
direction between each pair of vertices of the graph.

1) Perform DFS1 traversal of graph and push node to stack before returning
2) Find transpose of graph (reverse all the edges)
3) Pop nodes one by one from stack  and again do DFS2 on modified graph
   (each DFS2 traversal will form a SCC)

- time: O(E+V) [2 dfs + 1 reverse the graph edges]
*/

class Graph{
    int N, E;
    vector<int> *adj, *rev;

public:
    Graph(int N){
        this->N = N;
        adj = new vector<int>[N];
        rev = new vector<int>[N];
    }

    void addEdge(int from, int to){
        adj[from].push_back(to);
    }

    void findTranposeOfAGraph(){
        for(int from=0; from<N; from++){
            for(int to : adj[from]){
                rev[to].push_back(from);
            }
        }
    }

    void dfs1(int u, vector<bool> &visited, stack<int> &myStack){
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                dfs1(v, visited, myStack);
            }
        }
        myStack.push(u);
    }

    void dfs2(int from, vector<bool> &visited, vector<int> &component){
        visited[from] = true;
        component.push_back(from);
        for(int to : rev[from]){
            if(!visited[to]){
                dfs2(to, visited, component);
            }
        }
    }

    void findSCC(){
        vector<bool> visited(N, false);
        stack<int> myStack;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs1(i, visited, myStack);
            }
        }

        // mark all nodes again unvisited to do next dfs2
        for(int i=0; i<N; i++)
            visited[i] = false;

        // find tranpose of given graph
        findTranposeOfAGraph();
        
        int countSCC = 0;
        vector<vector<int>> stronglyConnectedComponents;
        while(!myStack.empty()){
            int node = myStack.top();
            myStack.pop();
            if(!visited[node]){
                countSCC++;
                vector<int> component;
                dfs2(node, visited, component);
                stronglyConnectedComponents.push_back(component);
            }
        }

        cout << "Number of strongly connected components:" << countSCC << "\n";
        cout << "SCCs: \n";
        for(auto& component : stronglyConnectedComponents){
            for(auto node : component){
                cout << node << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);   
    g.addEdge(5, 3);
    g.findSCC();
}

/*
Number of strongly connected components:2
SCCs: 
0 2 1
3 5 4
*/