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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void primeSeive(vector<bool> & primes, long long n)
{
	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i < n; i++)
	{
		if (primes[i])
		{
			for (int j = 0; j < n / i; j++)
			{
				if (i < 10000 && (i*i) + (i * j) < n)
				{
					primes[(i*i) + (i * j)] = false;
				}
			}
		}
	}
}

int main()
{
	ll i, j, k;
	ll cases;
	ll diffs;
	string start, finish, temp;
	map<string, vector<string > >::iterator itr;
	vector<bool> primes(10000, true);
	vector<string> primeRange;
	map < string, vector < string > > adj;
	map < string, bool> seen;
	map < string, int> dist;
	primeSeive(primes, 10000);
	for (i = 1000; i < 10000; i++)
	{
		if (primes[i])
		{
			primeRange.push_back(to_string(i));
		}
	}

	for (i = 0; i < primeRange.size(); i++)
	{
		for (j = i + 1; j < primeRange.size(); j++)
		{
			diffs = 0;
			for (k = 0; k < 4; k++)
			{
				if (primeRange[i][k] != primeRange[j][k])
				{
					diffs++;
				}
			}
			if (diffs == 1)
			{
				adj[primeRange[i]].push_back(primeRange[j]);
				adj[primeRange[j]].push_back(primeRange[i]);
			}
		}
	}

	
	
	
	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		cin >> start >> finish;
		deque<string > q;
		itr = adj.begin();
		while (itr != adj.end())
		{
			seen[(*itr).first] = false;
			dist[(*itr).first] = -1;
			itr++;
		}
		q.push_back(start);
		dist[start] = 0;
		while (!q.empty())
		{
			temp = q.front();
			q.pop_front();
			for (auto item : adj[temp])
			{
				if (dist[item] == -1) {
					dist[item] = dist[temp] + 1;
					q.push_back(item);
				}
			}
		}
		if (dist[finish] == -1)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << dist[finish] << "\n";
		}
	}

	return 0;
}
