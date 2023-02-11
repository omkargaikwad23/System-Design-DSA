#include <bits/stdc++.h>
using namespace std;
// Depth first search
// time : O(n+m), space : O(n*m)

vector<int>result;

void dfs(vector<int>adj[], int s, bool visited[]){
    visited[s] = true;
    result.push_back(s);
    for(auto u : adj[s]){
        if(!visited[u])
            dfs(adj, u, visited);
    }
}

int main(){
    // n - number of nodes 
    // m - number of edges
    cout << "Enter number of nodes & edges: ";
    int n, m;
    cin >> n >> m;

    // array of vectos - adjancency matrix
    vector<int>adj[n+1];
    cout << "Enter: (start -> end)\n";
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        // undirected graph
        // adj[y].push_back(x);
    }
    cout << "Enter starting node: " ;
    int s; cin >> s;
    // to keep track of visited nodes
    bool visited[n+1];
    memset(visited, false, sizeof(visited));

    dfs(adj, s, visited);

    cout << "DFS of given graph:\n";
    for(auto i:result){
        cout << i << " ";
    }
}