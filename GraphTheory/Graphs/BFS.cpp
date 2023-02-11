#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v;			// no of vertices
	list<int> *adj; // Pointer to an array containing adjacency list
public:
	Graph(int); // constructor
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	vector<bool>visited(v, false);
	vector<int>ans;
	list<int> queue;   // create queue for DFS
	visited[s] = true; // Mark the current node as visited and enqueue it
	queue.push_back(s);

	list<int>::iterator i;

	while (!queue.empty())
	{
		s = queue.front(); // Dequeue a vertex from queue and print it
		queue.pop_front();
		ans.push_back(s);

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	for(auto i : ans){
		cout << i << " ";
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.BFS(2);

	return 0;
}