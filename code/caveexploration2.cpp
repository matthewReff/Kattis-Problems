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
#include <stack>

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


int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    ll n;
    cin >> n;
    ll temp;
    set<int> vals;
    vector<int> rocks(n*n,0);
    vector<bool> used(n*n, false);
    parent.resize(n*n);
    sizeArr.resize(n*n);
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    	{
    		cin >> temp;
    		rocks[i*n+j] = temp;
    		vals.insert(temp);
    		make_set(i*n+j);
    	}
    }

    auto itr = vals.begin();

    bool finished = false;

    while(!finished)
    {
	    for(int i = 0; i < n; i++)
	    {
	    	for(int j = 0; j < n; j++)
	    	{
	    		if(rocks[i*n+j] <= (*itr))
	    		{
	    			int current = i*n+j;
	    			int up = (i+1)*n+j;
	    			if(i+1<n && rocks[up] <= (*itr))
	    			{
	    				union_sets(up,current);
	    			}

	    			int down = (i-1)*n+j;
	    			if(i-1 >= 0 && rocks[down] <= (*itr))
	    			{
	    				union_sets(down,current);
	    			}

	    			int right = i*n+j+1;
	    			if(j+1<n && rocks[right] <= (*itr))
	    			{
	    				union_sets(right, current);
	    			}

	    			int left = i*n+j-1;
	    			if(j-1>= 0 && rocks[left] <= (*itr))
	    			{
	    				union_sets(left, current);
	    			}
	    			used[current] = true;
	    		}
	    	}
	    }
	    finished = find_set(n*n-1) ==find_set(0);
	    if(finished)
	    {
	    	break;
	    }
	    itr++;
	}

	cout << (*itr) << "\n";
    return 0;
}
