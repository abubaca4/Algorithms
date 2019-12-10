#include <iostream>
#include "graph.hpp"
#include <utility>

using namespace std;

int main()
{
	size_t n;
	int start;
	cout << "Enter count of vertex:";
	cin >> n;
	cout << "Enter start vertex:";
	cin >> start;
	Graph<pair<int, size_t>, int> data(n);
	cout << "Enter matrix:" << endl;
	for (size_t i=0; i< n; i++)
		for (size_t j = 0; j < n; j++)
		{
			cin >> data.edge(i, j);
			if (data.edge(i, j) != -1)
				data.add_edge(i, j);
		}
	data.vertex(start) = make_pair(1, 0);
	for (size_t i = 0; i < start; i++)
		data.vertex(i) = make_pair(1, (size_t)1e9);
	for (size_t i = start + 1; i < n; i++)
		data.vertex(i) = make_pair(1, (size_t)1e9);
	while (start != -1)
	{
		for (auto it = data.vertex_n(start); it != data.end();++it)
		{
			if (data.vertex(*it).second > data.vertex(start).second + data.edge(start, *it))
			{
				data.vertex(*it).second = data.vertex(start).second + data.edge(start, *it);
				data.vertex(*it).first = 0;
			}
		}
		data.vertex(start).first = -1;
		int min = -1;
		for (size_t i=0; i<n; i++)
			if (data.vertex(i).first == 0 && (min == -1 || data.vertex(i).second < data.vertex(min).second))
				min = i;
		start = min;
	}
	cout << "Distances to vertexs:" << endl;
	for (size_t i = 0; i < n; i++)
		cout << data.vertex(i).second << " ";
}