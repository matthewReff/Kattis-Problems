#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull i, j, k;
	deque<int> q = { 0 };
	int size, edges, src, dest, top;
	bool outPut = false;
	cin >> size >> edges;
	vector<bool> seen(size, false);
	seen[0] = true;
	vector<vector<int>> adj(size);

	for (i = 0; i < edges; i++)
	{
		cin >> src >> dest;
		adj[src-1].push_back(dest-1);
		adj[dest-1].push_back(src-1);
	}

	while (q.size())
	{
		top = q.front();
		q.pop_front();
		for (auto item : adj[top])
		{
			if (!seen[item])
			{
				seen[item] = true;
				q.push_back(item);
			}
		}
	}

	for(i = 0; i < size; i++)
	{
		if (!seen[i])
		{
			outPut = true;
			cout << i + 1 << "\n";
		}
	}
	if (!outPut)
	{
		cout << "Connected\n";
	}
	return 0;
}
