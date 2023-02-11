#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int>vi;

/*
WiKi -> Dijkstra's algorithm to find the shortest path between a and b. 
It picks the unvisited vertex with the lowest distance, calculates 
the distance through it to each unvisited neighbor, and updates 
the neighbor's distance if smaller. Mark visited (set to red) when done 
with neighbors.

time: O ( v^2 ) in general
time: O ( V + E logV ) with min heap priority queue
*/

class Graph{
    int n;
    list<pair<int, int>> *adjList;
public:
    Graph(int numNodes){
        this->n = n;
        adjList = new list<pair<int, int>>[n];
    }
    void addEdge(int from, int to, int weight){
        adjList[from].push_back({to, weight});
    }

    // @param start - node from where distances is to be calculated
    int dijkstra(int start, int end){
        int ans = -1;
        vector<bool>visited(n+1, false);
        vector<int>distance(n+1, INT_MAX); 
        distance[start] = 0;

        // stores <distance, node> pairs in increasing order (min heap)
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        pq.push({0, start});

        while(!pq.empty()){
            // pop the node with minimum distance
            int minValue = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            visited[index] = true;

            // We already found a better path before we got to
            // processing this node so we can ignore it.
            if(distance[index] < minValue) continue;

            for(auto& edge : adjList[index]){
                if(visited[edge.first]) continue;

                // Relax edge by updating minimum cost if applicable
                int newDist = distance[index] + edge.second;
                if(newDist < distance[edge.first]){
                    distance[edge.first] = newDist;
                    pq.push({newDist, edge.first});
                }
            }
            if(index==end){
                ans = distance[index];
            }
        }
        cout << "Distances from start node to all other nodes!\n";
        for(int i=1; i<=8; i++){
            cout << i << "->" << distance[i] << "\n";
        }
        return ans;
    }
};

int main()
{
    Graph g(8);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 8);
    g.addEdge(3, 7, 11);
    g.addEdge(4, 5, 4);
    g.addEdge(4, 6, 5);
    g.addEdge(4, 7, 2);
    g.addEdge(5, 8, 9);
    g.addEdge(6, 8, 1);
    g.addEdge(7, 8, 2);
    
    int shortestDist = g.dijkstra(1, 8);
    cout << "Shortest distance between start and end node: ";
    cout << shortestDist << endl;

    return 0;
}

/*
OUTPUT:
Distances from start node to all other nodes!    
1->0
2->3
3->6
4->7
5->11
6->12
7->9
8->11
Shortest distance between start and end node: 11 1
*/

/*
using pii = pair<int,int>;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, S});
    
    while(!pq.empty()){
        int minDist = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        if(dist[index] < minDist) continue;
        
        for(auto& edge : adj[index]){
            int newDist = dist[index] + edge[1];
            if(newDist < dist[edge[0]]){
                dist[edge[0]] = newDist;
                pq.push({newDist, edge[0]});
            }
        }
    }
    return dist;
}
*/