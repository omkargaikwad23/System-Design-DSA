#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int from, to, cost;
    Edge(int from, int to, int cost){
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

struct DSU{
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
    int n;
    DSU(int _n){
        n = _n;
        parent.assign(n+1, 0);
        rank.assign(n+1, 0);
        size.assign(n+1, 0);
        for(int  i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1; // each node considered as component with size one and it's parent is that node itself
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]); //path compression
    }

    void merge(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return; //both are in same connected component

        if(rank[u] > rank[v]){
            parent[v] = u;
            size[u] += size[v];
        } else if(rank[u] < rank[v]){
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
            rank[u]++;
        }
    }
};

void printMstEdges(vector<Edge> &mstEdges, int mstCost){
    cout << "MST cost is : " << mstCost << "\n";
    cout << "Edges in MST are: \n";
    for(auto& e : mstEdges){
        cout << e.from << " to " << e.to << " with cost of " << e.cost << endl;
    }
}

bool comp(Edge &e1, Edge &e2){
    return e1.cost < e2.cost;
}

void Kruskal(vector<Edge> &edges, int V, int E){
    DSU ds(V);
    
    // sort edges by increaing their weights
    sort(edges.begin(), edges.end(), comp);
    int mstCost = 0;
    vector<Edge>mstEdges;

    for(Edge& edge : edges){
        if(ds.findParent(edge.from) != ds.findParent(edge.to)){
            mstCost += edge.cost;
            mstEdges.push_back(Edge(edge.from, edge.to, edge.cost));
            ds.merge(edge.from, edge.to);
        }
    }

    printMstEdges(mstEdges, mstCost);
}

int main(){
    int V  = 9, E = 6;
    vector<Edge>edges;

    edges.push_back(Edge(0, 1, 2));
    edges.push_back(Edge(0, 3, 6));
    edges.push_back(Edge(1, 3, 8));
    edges.push_back(Edge(1, 4, 3));
    edges.push_back(Edge(1, 2, 3));
    edges.push_back(Edge(2, 4, 7));

    Kruskal(edges, V, E);
}

/*
MST cost is : 14
Edges in MST are:
0 to 1 with cost of 2        
1 to 4 with cost of 3        
1 to 2 with cost of 3        
0 to 3 with cost of 6 
*/