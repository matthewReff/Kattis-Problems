#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const ll INF = ll(1) << 60;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<ll> & d, vector<ll> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    ll BIG_NUM = ll(1) << 60;
    ll nodes, edges;
    cin >> nodes >> edges;
    ll temp;
    adj.resize(nodes);
    set<ll> ballLocs;
    ll src, dest, dist;

    for(i = 0; i < edges; i++)
    {
    	cin >> src >> dest >> dist;
    	src--;
    	dest--;
    	adj[src].push_back(make_pair(dest, dist));
    	adj[dest].push_back(make_pair(src, dist));
    }

    for(i = 0; i < 7; i++)
    {
    	cin >> temp;
    	temp--;
    	ballLocs.insert(temp);
    }
    ballLocs.insert(0);
    //vector<vector<ll> > dis(ballLocs.size(), vector<ll>(ballLocs.size()));

    map<ll, vector<ll>> nodeDists;
	for(auto val : ballLocs)
	{
		vector<ll> d;
		vector<ll> p;
		dijkstra(val, d, p);

		//cout << "val " << val << ": ";
		nodeDists[val] = d;
		//for(auto thing : d)
		//{
		//		cout << thing << " ";
		//	}

		//cout << "\n";
	} 


	vector<ll> loc;
	set<ll>::iterator sit = ballLocs.begin();

	while(sit != ballLocs.end())
	{
		loc.push_back(*sit);
		sit++;
	} 

	sort(loc.begin(),loc.end());

	ll runMin = BIG_NUM;

	if(loc.size() == 1)
	{
		cout<<"0"<<endl;
		return 0;
	}

	do
	{
		ll currD = 0;
		for(int i = 0; i < loc.size()-1; i++)
		{
			currD += nodeDists[loc[i]][loc[i+1]];
			//cout << loc[i] << " to " << loc[i+1] << " is " << nodeDists[loc[i]][loc[i+1]] << "\n";
			//cout << currD << "\n";
		}
		//cout << "curr: " << currD << " max: " << runMin << "\n"; 
		if(currD < runMin)
			runMin = currD;

	}while(next_permutation(loc.begin()+1,loc.end()));

	if(runMin == BIG_NUM)
	{
		cout << "-1\n";
	}
	else
	{
		cout << runMin << "\n";
	}
    return 0;
}
