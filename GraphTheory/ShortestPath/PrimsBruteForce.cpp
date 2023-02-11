#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Edge{
    int from, to, cost;
    Edge(int from, int to, int cost){
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};


class Prims{
    int N;
    vector<pair<int, int>> *adj;
public:
    Prims(int N){
        this->N = N;
        adj = new vector<pair<int, int>>[N];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void findMST(){
        vector<int> parent(N, -1);
        vector<bool> inMst(N, false);
        vector<int> weight(N, INT_MAX);
        
        weight[0] = 0;

        for(int i=0; i < N-1; i++){
            int minWeight = INT_MAX, minIndex = 0;

            // select next edge having minimum cost and not already taken
            for(int v=0; v<N; v++){
                if(!inMst[v] && weight[v] < minWeight){
                    minWeight = weight[v], minIndex = v;
                }
            }

            // include next promising node in MST
            inMst[minIndex] = true;

            // relax the edges and update parent array
            for(auto edge : adj[minIndex]){
                int to = edge.first, cost = cost;
                if(!inMst[to] && cost < weight[to]){
                    parent[to] = minIndex, weight[to] = cost;
                }
            }
        }

        cout << "Edges in MST:\n";
        for(int i=1; i<parent.size(); i++){
            cout << parent[i] << " to " << i << "\n";
        }
    }
};


int main(){
    Prims g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 4, 7);

    g.findMST();
}