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

vector<ll> parent;
vector<ll> sizeArr;

//shamelessly stolen from
//https://cp-algorithms.com/data_structures/disjoint_set_union.html
void make_set(int v) {
    parent[v] = v;
    sizeArr[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizeArr[a] < sizeArr[b])
            swap(a, b);
        parent[b] = a;
        sizeArr[a] += sizeArr[b];
    }
}

// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
bool isCyclicUtil(int v, vector<vector<int>> & adj, vector<bool> & visited, vector<bool> & currentUsing)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        currentUsing[v] = true;
  
        // Recur for all the vertices adjacent to this vertex
        for(int i = 0; i < (int)adj[v].size(); ++i)
        {
            if ( !visited[adj[v][i]] && isCyclicUtil(adj[v][i], adj, visited, currentUsing))
                return true;
            else if (currentUsing[adj[v][i]])
                return true;
        }
  
    }
    currentUsing[v] = false;  // remove the vertex from recursion stack
    return false;
}

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll players, matches;
    cin >> players >> matches;

    parent.resize(players);
    sizeArr.resize(players);

    for(int i = 0; i < players; i++)
    {
    	make_set(i);
    }

	int left;
	int right;
	char symbol;
	vector<vector<int>> adj(players, vector<int>());
	vector<pair<int, int>> greaterPairs;
    for(int i = 0; i < matches; i++)
    {
    	cin >> left >> symbol >> right;

    	if(symbol == '=')
    	{
    		union_sets(left, right);
    	}
    	else
    	{
    		greaterPairs.push_back(make_pair(left, right));
    	}
    }

    for(int i = 0; i < greaterPairs.size(); i++)
    {
    	left = greaterPairs[i].first;
    	right = greaterPairs[i].second;
    	if(find_set(left) == find_set(right))
		{
			cout << "inconsistent\n";
			return 0;
		}
		//cout << "Adding: " << left << " " << right << "\n";
		adj[find_set(left)].push_back(find_set(right));
    }

    for(int i = 0; i < players; i++)
    {
    	sort(adj[i].begin(), adj[i].end());
    	auto it = unique(adj[i].begin(), adj[i].end());
    	adj[i].erase(it, adj[i].end());
    }
    vector<bool> visited(players, false);
    vector<bool> currentUsing(players, false);

    /*
    cout << "sets: ";
    for(int i = 0; i < players; i++)
    {
    	cout << i << " " << find_set(i) << "\n";
    }
    cout << "adj: ";
    for(int i = 0; i < players; i++)
    {
    	cout << i << ":\n";
    	for(int j = 0; j < adj[i].size(); j++)
    	{
    		cout << adj[i][j] << " ";
    	}
    	cout << "\n";
    }
		*/
    bool validGraph = true;
    for(int i = 0; i < players; i++)
    {
    	int temp = find_set(i);
    	if(!visited[temp] && isCyclicUtil(temp, adj, visited, currentUsing))
    	{
    		//cout << "AAA died:" << i << " " << temp << "\n";
    		validGraph = false;
    	}
    }

    if(validGraph)
    {
    	cout << "consistent\n";
	}
	else
	{
		cout << "inconsistent\n";

	}
    return 0;
}
