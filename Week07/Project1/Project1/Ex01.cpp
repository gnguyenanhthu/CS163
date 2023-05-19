#include <iostream>
using namespace std;

class Graph {
public:
	void initial(int n);
	void addedge(int i, int j);
	void DFS(int n, int x);
private:
	int **adjmatrix;
	int v;
	int *visited;
	void initial(int *&visited, int **&a, int &v, int n);
	void addedge(int **&a, int i, int j);
	void DFS(int *visited, int **a, int n, int x);
};

void Graph::initial(int n) {
	initial(visited, adjmatrix, v, n);
}

void Graph::initial(int *&visited, int **&a, int &v, int n) {
	v = n;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	}
	visited = new int[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;
}

void Graph::addedge(int **&a, int i, int j){
	a[i][j] = 1;
	a[j][i] = 1;
}

void Graph::addedge(int i, int j) {
	addedge(adjmatrix, i, j);
}

void Graph::DFS(int *visited, int **a, int n, int x) {
	visited[x] = 1;
	cout << x <<" ";
	for(int i=0;i<n;i++)
		if (a[x][i]==1 && visited[i] == 0)
			DFS(visited, a, n, i);
}

void Graph::DFS(int n, int x) {
	DFS(visited,adjmatrix, n, x);
}

int main() {
	Graph g;
	int n, e, i, j, x;
	cout << "Input number of vertices: ";
	cin >> n;
	g.initial(n);
	cout << "Input number of edges: ";
	cin >> e;
	for (int k = 0; k < e; k++){
		cout << "Input adjency matrix: ";
		cin >> i >> j;
		g.addedge(i, j);
	}
	cout << "Input the starting vertex: ";
	cin >> x;
	g.DFS(n, x);
	system("pause");
	return 0;
}