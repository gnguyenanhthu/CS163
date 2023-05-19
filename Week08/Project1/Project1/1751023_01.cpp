#include <iostream>
using namespace std;

class Graph {
public:
	void initial(int n);
	void addedge(int i, int j, int w);
	void dijkstra(int n, int begin);
private:
	int **adjmatrix;
	int v;
	void initial(int **&a, int &v, int n);
	void addedge(int **&a, int i, int j, int w);
	int mindistance(int d[], bool shortest[], int n);
	void dijkstra(int **a, int n, int begin);
	void print(int d[], int n);
};
void Graph::initial(int n) {
	initial(adjmatrix, v, n);
}

void Graph::initial(int **&a, int &v, int n) {
	v = n;
	a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	}
}

void Graph::addedge(int **&a, int i, int j, int w) {
	a[i][j] = w;
	a[j][i] = w;
}

void Graph::addedge(int i, int j, int w) {
	addedge(adjmatrix, i, j, w);
}

int Graph::mindistance(int d[], bool shortest[], int n) {
	int min = INT_MAX, minindex;
	for (int i = 0; i < n; i++)
		if (shortest == false && d[i] <= min)
			min = d[i], minindex = i;
	return minindex;
}

void Graph::dijkstra(int n, int begin) {
	dijkstra(adjmatrix, n, begin);
}

void Graph::dijkstra(int **a, int n, int begin) {
	int *d = new int [n];
	bool *shortest = new bool [n];
	for (int i = 0; i < n; i++) {
		d[i] = INT_MAX, shortest[i] = false;
	}
	d[begin] = 0;
	for (int c = 0; c < n - 1; c++) {
		int u = mindistance(d, shortest, n);
		shortest[u] = true;
		for (int j = 0; j < n; j++)
			if (!shortest[j] && a[u][j] && d[u] != INT_MAX&&d[u] + a[u][j] < d[j])
				d[j] = d[u] + a[u][j];
	}
	print(d, n);
}

void Graph::print(int d[], int n) {
	cout << "Vertex     Distance from Source" << endl;
	for (int i = 0; i < n; i++)
		cout << i << "                " << d[i] << endl;
}

int main() {
	Graph g;
	int n, e, i, j, w, x;
	cout << "Input number of vertices: ";
	cin >> n;
	g.initial(n);
	cout << "Input number of edges: ";
	cin >> e;
	for (int k = 0; k < e; k++) {
		cout << "Input adjency matrix: ";
		cin >> i >> j >> w;
		g.addedge(i, j, w);
	}
	cout << "Input the starting vertex: ";
	cin >> x;
	g.dijkstra(n, x);
	system("pause");
	return 0;
}