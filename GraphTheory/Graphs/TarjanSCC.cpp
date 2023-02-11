#include <bits/stdc++.h>
using namespace std;

class TarjanScc {
    int n;
    vector<vector<int>> graph;
public:
    TarjanScc(int _n){
        n = _n;
    }
    void addEdge(int u, int v){
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }

};

int main(){

}