#include <iostream>
using namespace std;

class Graph {
public:
	void initial(int n);
	void addedge(int i, int j);
	bool isconnected();
private:
	int **adjmatrix;
	int v;
	int *visited;
	void initial(int *&visited, int **&a, int &v, int n);
	void addedge(int **&a, int i, int j);
	bool isconnected(int **a, int n);
	void fill(int **a, int i, int n, bool *check);
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

void Graph::addedge(int **&a, int i, int j) {
	a[i][j] = 1;
	a[j][i] = 1;
}

void Graph::addedge(int i, int j) {
	addedge(adjmatrix, i, j);
}

bool Graph::isconnected(int **a,int n) {
	bool *check = new bool[n];
	for (int i = 0; i < n; i++)
		check[i] = false;
	fill(a, 0, n, check);
	for (int i = 0; i < n; i++)
		if (!check[i])
			return false;
	return true;
}

void Graph::fill(int **a, int i, int n, bool *check) {
	check[i] = true;
	for (int j = 0; j < n; j++)
		if (a[i][j] && !check[j])
			fill(a, j, n, check);
}

bool Graph::isconnected() {
	return isconnected(adjmatrix, v);
}

int main() {
	Graph g;
	int n, e, i, j;
	cout << "Input number of vertices: ";
	cin >> n;
	g.initial(n);
	cout << "Input number of edges: ";
	cin >> e;
	for (int k = 0; k < e; k++) {
		cout << "Input adjency matrix: ";
		cin >> i >> j;
		g.addedge(i, j);
	}
	if (g.isconnected())
		cout << "Graph is connected." << endl;
	else
		cout << "Graph is not connected." << endl;
	system("pause");
	return 0;
}