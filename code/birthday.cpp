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
#include <stack>
#include <unordered_map>

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
	ll i, j, k;

	ll p, c;
	ll src, dest;
	while (cin >> p >> c && p != 0)
	{
		vector<vector<ll>> adj(p);
		vector<pair<ll, ll>> edges;
		ll leastIn = 999999;
		for (i = 0; i < c; i++ )
		{
			cin >> src >> dest;
			adj[src].push_back(dest);
			adj[dest].push_back(src);
			edges.push_back(make_pair(src, dest));
		}

		bool valid = true;
		for (i = 0; i < edges.size(); i++)
		{
			vector<bool> visited(p, false);
			queue<ll> q;

			q.push(0);
			visited[0] = true;
			ll touched = 1;
			while (q.size())
			{
				ll front = q.front();
				q.pop();
				for (auto thing : adj[front])
				{
					if (!visited[thing] && !(front == edges[i].first && thing == edges[i].second ||
						front == edges[i].second && thing == edges[i].first))
					{
						q.push(thing);
						visited[thing] = true;
						touched++;
					}
				}
			}
			if (touched != p)
			{
				valid = false;
				break;
			}
		}
		if(valid)
		{
			cout << "No\n";
		}
		else
		{
			cout << "Yes\n";
		}
	}
	return 0;
}