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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll users, links, index, minutes;
    cin >> users >> links >> index >> minutes;

    if(minutes == 0)
    {
    	cout << "0\n";
    	return 0;
    }
    unordered_map<ll, ll> tracking;
    unordered_map<ll, ll> prevTracking;
    vector<vector<ll>> adj(users, vector<ll>());

    ll src, dest;

    for(int i = 0; i < links; i++)
    {
    	cin >> src >> dest;
    	adj[dest].push_back(src);
    	adj[src].push_back(dest);
    }

	tracking[index] += 1;
    for(int i = 0; i < minutes; i++)
    {
    	prevTracking = tracking;
    	tracking.clear();

    	auto itr = prevTracking.begin();
    	while(itr != prevTracking.end())
    	{
    		if(itr->second != 0)
    		{
    			for(auto nextTo : adj[itr->first])
    			{
    				tracking[nextTo] += itr->second;
    			}
    		}
    		itr++;
    	}
    }

    ll total = 0;
    auto itr = tracking.begin();
    while(itr != tracking.end())
    {
    	total += (itr->second);
    	itr++;
    }

    cout << total << "\n";

    return 0;
}
