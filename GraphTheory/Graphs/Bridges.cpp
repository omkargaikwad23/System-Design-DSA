#include <bits/stdc++.h>
using namespace std;

/*
Bridge: an edge of a graph whose deletion increases 
the graph's number of connected components.
*/

class Graph{
    int N;
    list<int> *adj;
    vector<int> tInsert, tLow;
    vector<bool> visited;
public:
    Graph(int n){
        this->N = n;
        adj = new list<int>[n];
        tInsert.resize(n, -1);
        tLow.resize(n, -1);
        visited.resize(n, false);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int parent, int timer){
        visited[node] = true;
        tInsert[node] = tLow[node] = timer++;

        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!visited[it]){
                dfs(it, node, timer);
                tLow[node] = min(tLow[node], tLow[it]); 
                if(tLow[it] > tInsert[node]) {
                    cout << node << " " << it << endl;
                }
            }
            else {
                tLow[node] = min(tLow[node], tInsert[it]);
            }
        }
    }
    
    void findBridges(){
        int timer = 0;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs(i, -1, timer);
            }
        }
    }
};


int main(){
    Graph g(5);
    g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.findBridges();
}

/*
tim: O(N)
Edges that divide graph into multiple components
3 4
2 3
*/
