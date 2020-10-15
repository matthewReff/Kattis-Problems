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

map<string, string> parent;
map<string, ll> sizeArr;
void make_set(string v)
{
	parent[v] = v;
	sizeArr[v] = 1;
}

string find_set(string const v)
{
	if(v == parent[v])
	{
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

int union_sets(string a, string b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if(sizeArr[a] < sizeArr[b])
		{
			swap(a, b);
		}
		parent[b] = a;
		sizeArr[a] += sizeArr[b];
	}
	return sizeArr[a];
}


int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll cases;
    string name1, name2;
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
    	sizeArr.clear();
    	parent.clear();
    	ll relationships;
    	cin >> relationships;
    	for(j = 0; j < relationships; j++)
    	{
    		cin >> name1 >> name2;
    		if(parent.find(name1) == parent.end())
    		{
    			make_set(name1);
    		}	
    		if(parent.find(name2) == parent.end())
    		{
    			make_set(name2);
    		}
    		cout << union_sets(name1, name2) << "\n";
    		//for(auto parentPair : parent)
    		//{
    		//	cout << parentPair.first << " " << parentPair.second << "\n";
    		//}
    	}
    }
    return 0;
}
//Start: Wed Jan 29 09:47:10 MST 2020
//Stop: Wed Jan 29 09:54:55 MST 2020
//Start: Wed Jan 29 09:57:53 MST 2020
//Stop: Wed Jan 29 10:05:54 MST 2020
