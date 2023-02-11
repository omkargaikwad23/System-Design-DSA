#include <bits/stdc++.h>
using namespace std;

/*
 topological sort is only possible for DAG
 Kahns algorithm can detect cycles in directed grpah 
 
 time: O(E+V) space: O(V)
 filling inDegree -> O(V+E)
 filling queue -> O(V)
 processing queue -> O(E+V)

 OUTLINE:
 1) Compute inDegree of all nodes and add nodes having inDegree 0 in queue
 2) Process each node(add in topoOrder array) in queue and decrement the inDegree of neighbours by 1
 3) if indegree of neighbour becomes 0 then add it in queue
 4) if topoOrder.size()==V then cycle is not there in graph
*/

class Graph{
    int N, E;
    vector<int> *adj;
public:
    Graph(int N){
        this->N = N;
        adj = new vector<int>[N];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    vector<int> computeInDegrees(){
        vector<int>inDegree(N, 0);
        for(int i=0; i<N; i++){
            // edge is directed from i to it
            for(auto it : adj[i]){
                inDegree[it]++;
            }
        }
        return inDegree;
    }

    vector<int> topoOrdering(){
        queue<int>q; // to maintain next 0 indegree node
        vector<int> inDegree, ordering;
        inDegree = computeInDegrees();

        for(int i=0; i<N; i++){
            if(inDegree[i]==0) q.push(i);
        }

        int cnt = 0; // to detect cycle
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            ordering.push_back(node);
            // decrement degrees of adjacent nodes of current node
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }

        // cnt == N orering is possible, graph is DAG
        if(cnt!=N) return {};
        return ordering;
    }
};


int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);   

    vector<int> topoOrder = g.topoOrdering(); 

    for(auto node : topoOrder){
        cout << node << " ";
    }
    // OUTPUT: 0 3 1 2 4 5
}