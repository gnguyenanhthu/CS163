#include <iostream>
using namespace std;

int parent(int a[], int m, int i);
int left(int a[], int n, int i);
int right(int a[], int n, int i);
void maxHeapify(int a[], int n, int i);
void buildMaxHeap(int a[], int n);
void heapSort(int a[], int n);
void print(int a[], int n);

int main()
{
	int *a, n, i, m;
	cout << "Input number of elements: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Input a[" << i << "]: ";
		cin >> a[i];
	}
	cout << "Input index: ";
	cin >> i;
	cout << "Parent's index: " << parent(a, n, i) << endl;
	cout << "Left's index: " << left(a, n, i) << endl;
	cout << "Right's index: " << right(a, n, i) << endl;
	cout << "Input max hepify index: ";
	cin >> m;
	maxHeapify(a, n, m);
	buildMaxHeap(a, n);
	cout << "Build max heap: ";
	print(a, n);
	heapSort(a, n);
	cout << "Heap sort: ";
	print(a, n);
	system("pause");
	return 0;
}

int parent(int a[], int m, int i)
{
	if (i != 0)
		return (i - 1) / 2;
	return NULL;
}

int left(int a[], int n, int i)
{
	if ((2 * i + 1) < n)
		return (2 * i + 1);
	return NULL;
}

int right(int a[], int n, int i)
{
	if ((2 * i + 2) < n)
		return (2 * i + 2);
	return NULL;
}

void maxHeapify(int a[], int n, int i)
{
	int c, t;
	t = a[i];
	c = 2 * i + 1;
	while (c <= n)
	{
		if (a[c] < a[c + 1] && c < n)
			c++;
		if (t > a[c])
			break;
		else if (t <= a[c])
		{
			a[(c - 1) / 2] = a[c];
			c = 2 * c + 1;
		}
	}
	a[(c - 1) / 2] = t;
	return;
}

void buildMaxHeap(int a[], int n)
{
	for (int i = (n / 2)-1; i >= 0; i--)
	{
		maxHeapify(a, i, n);
	}
}

void heapSort(int a[], int n)
{
	buildMaxHeap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		maxHeapify(a, i, 0);
	}
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}