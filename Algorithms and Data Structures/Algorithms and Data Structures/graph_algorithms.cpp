// IDDFS, Floyd-Warshall (allows negatives), topological sort, Kruskal, Prim, Eulerian, Bellman-Ford

#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;
typedef pair<int, int> PII;

//O(E)
int depth_first_search(vector< vector < int> > adjacency_list, int source) {
	vector<int> distance(adjacency_list.size(), INT_MAX);
	vector<int> previous_vertex(adjacency_list.size(), -1);
	vector<bool> visited(adjacency_list.size());

	stack<int> unvisited_vertices;
	unvisited_vertices.push(source);

	while (!unvisited_vertices.empty()) {
		int current_vertex = unvisited_vertices.top();
		visited[current_vertex] = true;

		unvisited_vertices.pop();

		for (int neighbor_vertex : adjacency_list[source]) {
			if (distance[current_vertex] + 1 < distance[neighbor_vertex]) {
				distance[neighbor_vertex] = distance[current_vertex] + 1;
				previous_vertex[neighbor_vertex] = current_vertex;

				unvisited_vertices.push(neighbor_vertex);
			}
		}
	}
}

//O(E)
int breadth_first_search(vector< vector < int> > adjacency_list, int source) {
	vector<int> distance(adjacency_list.size(), INT_MAX);
	vector<int> previous_vertex(adjacency_list.size(), -1);
	vector<bool> visited(adjacency_list.size());

	queue<int> unvisited_vertices;
	unvisited_vertices.push(source);

	while (!unvisited_vertices.empty()) {
		int current_vertex = unvisited_vertices.front();
		visited[current_vertex] = true;

		unvisited_vertices.pop();

		for (int neighbor_vertex : adjacency_list[source]) {
			if (neighbor_vertex == INT_MAX) {
				distance[neighbor_vertex] = distance[current_vertex] + 1;
				previous_vertex[neighbor_vertex] = current_vertex;

				unvisited_vertices.push(neighbor_vertex);
			}
		}
	}
}

// O(V^2), directed graph, non-negative weights
int dijkstra(vector< vector<int> > adjacency_matrix, int source, int target) {
	//Initialization
	int n = adjacency_matrix.size();
	vector<int> distance(n, INT_MAX);
	vector<int> previous_vertex(n, -1);
	vector<bool> visited(n);
	distance[source] = 0;

	//Main loop
	for (int i = 0; i < n; ++i) { 
		int current_vertex = -1;
		for (int j = 0; j < n; ++j) { //Find best vertex
			if (visited[j]) continue;
			if (current_vertex == -1 || distance[j] < distance[current_vertex]) {
				current_vertex = j; }
		}
		visited[current_vertex] = true;

		for (int neighbor_vertex : adjacency_matrix[current_vertex]) { //Check neighbors
			if (distance[current_vertex] + adjacency_matrix[current_vertex][neighbor_vertex] < distance[neighbor_vertex]) {
				distance[neighbor_vertex] = distance[current_vertex] + adjacency_matrix[current_vertex][neighbor_vertex];

				previous_vertex[neighbor_vertex] = current_vertex;
			}
		}
	} 
	return distance[target];
}

// O(ElogV), directed graph, non-negative weights
int sparse_dijkstra(const vector< vector<PII> > adjacency_list, int source, int target) {
	// Initialization
	vector<int> distance(adjacency_list.size(), INT_MAX); // Distance from source
	vector<int> previous_vertex(adjacency_list.size(), -1); // Previous vertex in shortest path
	vector<bool> visited(adjacency_list.size());
	distance[source] = 0;

	set< pair<int, int> > unvisited_vertices; // Vertices sorted by distance from source
	unvisited_vertices.insert(PII(0, source));

	//Main loop
	while (!unvisited_vertices.empty()) {
		int current_vertex = unvisited_vertices.begin()->second; // Get best vertex
		unvisited_vertices.erase(unvisited_vertices.begin());
		visited[current_vertex] = true;

		for (PII edge : adjacency_list[current_vertex]) { // Check neighbors for shorter paths
			int neighbor_vertex = edge.second;
			int edge_length = edge.first;
			if (distance[current_vertex] + edge_length < distance[neighbor_vertex]) {
				distance[neighbor_vertex] = distance[current_vertex] + edge_length;

				unvisited_vertices.erase(edge); //Update distances
				unvisited_vertices.insert(PII(distance[neighbor_vertex], neighbor_vertex));

				previous_vertex[neighbor_vertex] = current_vertex;
			}
		}
	}
	return distance[target];
}