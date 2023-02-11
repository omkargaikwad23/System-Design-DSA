#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//time : O(4*alpha)

struct DSU{
    vector<int>parent;
    vector<int>rank;
    vector<ll>size;
    int n;
    DSU(int _n){
        n = _n;
        parent.assign(n+1, 0);
        rank.assign(n+1, 0);
        size.assign(n+1, 1);
        for(int  i=0; i<=n; i++){
            parent[i] = i; // each node considered as component with size one and it's parent is that node itself
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void merge(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return; //both are in same connected component
 
        if (rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
};

int main(){
    DSU ds(1000);
    ds.merge(1, 2);
    ds.merge(2, 3);
    ds.merge(3, 4);
    ds.merge(5, 6);

    int parentA = ds.findParent(1);
    int parentB = ds.findParent(6);
    if(parentA == parentB){
        cout << "In same component";
    }else{
        cout << "In different component";
    }

}