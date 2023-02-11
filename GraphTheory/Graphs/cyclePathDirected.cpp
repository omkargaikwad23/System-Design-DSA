#include <bits/stdc++.h>
using namespace std;

bool isCycleUtil(int node, vector<bool>& vis, vector<bool>& dfsVis, vector<int> adj[]){
    vis[node] = true;
    dfsVis[node] = true;
    for(auto to : adj[node]){
        if(!vis[to]){
            if(isCycleUtil(to, vis, dfsVis, adj))
                return true;
        }
        else if(dfsVis[to]){    //'to' is true in vis and dfsVis stack
            return true;
        }
    }
    dfsVis[node] = false;   //backtrack the path
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<bool> vis(V, false);
    vector<bool> dfsVis(V, false);

    for(int i=0; i<V; i++){
        if(!vis[i])
            if(isCycleUtil(i, vis, dfsVis, adj))
                return true;
    }
    return false;
}

int main(){
    int V, E; 
    cin >> V >> E;
    vector<int> adj[V];

    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCycle(V, adj) << endl;
}