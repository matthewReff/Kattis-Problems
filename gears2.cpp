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

double distanceForm(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}
int main()
{
    ll i, j, k;
    ll num;
    cin >> num;
    double x, y, distance;
    vector<pair<ll, ll>> locations(num);
    vector<ll> diameters(num);
    vector<vector<ll>> adj(num);
    vector<int> direction(num, 0);
    vector<bool> visited(num, false);
    for(i = 0; i < num; i++)
    {
    	cin >> locations[i].first;
    	cin >> locations[i].second;
    	cin >> diameters[i];
    	for(j = i - 1; j >= 0; j--)
    	{
    		//cout << distanceForm(locations[i].first, locations[i].second, locations[j].first, locations[j].second) << " " << diameters[i] << " " << diameters[j] << "\n";
    		//	cout << "distance  " << i << " " << j << "\n";
    		if(abs(distanceForm(locations[i].first, locations[i].second, locations[j].first, locations[j].second) - diameters[i] - diameters[j] ) < 0.00001)
    		{
    			adj[i].push_back(j);
    			adj[j].push_back(i);
    			//cout << "Adding adj " << i << " " << j << "\n";
    		}
    	}
    }

    bool possible = true;
    queue<ll> q;

    direction[0] = 1;
    visited[0] = true;
    q.push(0);

    while(q.size())
    {
    	ll top = q.front();
    	q.pop();
    	//cout << "top: " << top << "\n";
    	for(auto edge : adj[top])
    	{
    		//cout << "edge: " << edge << "\n";
    		if(direction[edge] == direction[top] && direction[edge] != 0)
    		{
    			possible = false;
    		}
    		if(!visited[edge])
    		{
    			q.push(edge);
    			visited[edge] = true;
    			if(direction[top] == 1)
    			{
    				direction[edge] = 2;
    			}
    			else
    			{
    				direction[edge] = 1;
    			}
    		}
    	}
    }

    if(!possible)
    {
    	cout << "-1\n";
    }
    else if(!visited[num-1])
    {
    	cout << "0\n";
    }
    else
    {
    	int diaSrc = diameters[0];
    	int diaDest = diameters[num-1];
    	int gcd = __gcd(diaSrc, diaDest);

    	diaSrc /= gcd;
    	diaDest /= gcd;

    	if(direction[0] != direction[num-1])
    	{
    		diaSrc *= -1;
    	}
    	cout << diaDest << " " << diaSrc << "\n";
    }
    return 0;
}
