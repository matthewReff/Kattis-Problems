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

struct dijkEdge
{
    ll weight = 99999999;
    ll src = -1;
    ll dest = -1;
    bool operator<(dijkEdge r)
    {
        return weight < r.weight;
    }
};

bool operator<(const dijkEdge & l, const dijkEdge & r)
{
    return l.weight < r.weight;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    ll n, currentLoc, wantedLoc;
    ll usedEdges = 1;
    cin >> n >> currentLoc >> wantedLoc;
    vector<vector<ll>> adj(n); 
    for(i = 0; i < n; i++)
    {
        adj[i].resize(n);
        for(j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    
    vector<ll> distance(n);
    vector<bool> seen(n, false);
    
    //add first node
    seen[currentLoc] = true;
    for(i = 0; i < n; i++)
    {
        distance[i] = adj[currentLoc][i];
    }
    
    while(usedEdges != n)
    {
        ll shortest = 99999999;
        ll leastIndex;
        
        //find shorted unused node
        for(i = 0; i < n; i++)
        {
            if(!seen[i] && distance[i] < shortest)
            {
                shortest = distance[i];
                leastIndex = i;
            }
        }
        
        //massage from node
        for(i = 0; i < n; i++)
        {
            if(adj[leastIndex][i] != 0 && distance[i] > adj[leastIndex][i] + distance[leastIndex])
            {
                //cout << "path from " << leastIndex << " to " << i << " is better, with distance " << adj[leastIndex][i] + distance[leastIndex] << "\n";
                distance[i] = adj[leastIndex][i] + distance[leastIndex];
            }   
        }
        
        //mark node as seen
        seen[leastIndex] = true;
        usedEdges++;
        
        /*
        for(auto thing : distance)
        {
            cout << thing << "\n";
        }
        cout << "\n";
        */
    }
    
    
    cout << distance[wantedLoc] << "\n";
    return 0;
}
