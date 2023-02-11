#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int>vi;
/*
 An implementation of the Bellman-Ford algorithm. The algorithm finds the shortest path between
 a starting node and all other nodes in the graph. The algorithm also detects negative cycles.
 If a node is part of a negative cycle then the minimum cost for that node is set to
 NEGATIVE_INFINITY.

 @param edge_list - An edge list containing directed edges forming the graph
 @param V - The number of vertices in the graph.
 @param start - The id of the starting node
*/

// A directed edge
struct Edge
{
    float cost;
    int from, to;
    Edge(int from, int to, float cost){
        this->to = to;
        this->from = from;
        this->cost = cost;
    }
};

vector<int> bellmanFord(vector<vi>edge_list, int V, int start){
    vector<int>distance(V, 10e8);
    distance[start] = 0;

    // Only in the worst case does it take V-1 iterations for the Bellman-Ford
    // algorithm to complete. Another stopping condition is when we're unable to
    // relax an edge, this means we have reached the optimal solution early.
    bool relaxedAnEdge = true;

    // For each vertex, apply relaxation for all the edges
    for(int v=0; v < V-1 && relaxedAnEdge; v++){
       relaxedAnEdge = false;
       for(auto edge : edge_list){
           int newDist = distance[edge[0]] + edge[2]; // dist[edge.from] + edge.cost < dist[edge.to]
           if(newDist < distance[edge[1]]){
               distance[edge[1]] = newDist;
               relaxedAnEdge = true;
           }
       }
    }

    // Run algorithm a second time to detect which nodes are part
    // of a negative cycle. A negative cycle has occurred if we
    // can find a better path beyond the optimal solution.
    relaxedAnEdge = true;
    for(int v=0; v < V-1 && relaxedAnEdge; v++){
        relaxedAnEdge = false;
        for(auto edge : edge_list) {
            // dist[edge.from] + edge.cost < dist[edge.to]
            if (distance[edge[0]] + edge[2] < distance[edge[1]]){
                distance[edge[1]] = -10e8;
                relaxedAnEdge = true;
            }
        }
    }
    // Return the array containing the shortest distance to every node
    return distance;
}


int main(){
    int E = 10, V = 9, start = 0;
    vector<vi>edge_list;

    edge_list.push_back({0, 1, 1});
    edge_list.push_back({1, 2, 1});
    edge_list.push_back({2, 4, 1});
    edge_list.push_back({4, 3, -3});
    edge_list.push_back({3, 2, 1});
    edge_list.push_back({1, 5, 4});
    edge_list.push_back({1, 6, 4});
    edge_list.push_back({5, 6, 5});
    edge_list.push_back({6, 7, 4});
    edge_list.push_back({5, 7, 3});

    vi distance = bellmanFord(edge_list, V, start);
    for(int i=0; i<V; i++){
        printf("The cost to get from node %d to %d is %d \n", start, edge_list[i][1], distance[i]);  
    }
}

/*
The cost to get from node 0 to 1 is 0
The cost to get from node 0 to 2 is 1
The cost to get from node 0 to 4 is -1000000000    
The cost to get from node 0 to 3 is -1000000000    
The cost to get from node 0 to 2 is -1000000000    
The cost to get from node 0 to 5 is 5
The cost to get from node 0 to 6 is 5
The cost to get from node 0 to 6 is 8
The cost to get from node 0 to 7 is 1000000000 

1 2 5
1 3 3
1 4 7
2 6 2
2 4 3
3 4 1
4 6 2
*/