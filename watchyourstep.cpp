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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll exists;
    ll alreadyPresent = 0;
    ll possAdded = 0;
    vector<vector<int>> adj(n);
    for(i = 0; i < n; i++)
    {
    	for(j = 0; j < n; j++)
    	{
			cin >> exists;
			if(exists)
			{
				adj[i].push_back(j);
				alreadyPresent++;
			}    		
    	}
    }
    
    for(i = 0; i < n; i++)
    {
    	stack<int> s;
        vector<bool> visisted(n, false);

        s.push(i);
        visisted[i] = true;

        while(s.size())
        {
            int top = s.top();
            s.pop();
            for(auto nextTo : adj[top])
            {
                if(!visisted[nextTo])
                {
                    visisted[nextTo] = true;
                    s.push(nextTo);
                }
            }
        }

        for(j = 0; j < n; j++)
        {
        	if(visisted[j] && j != i)
        	{
        		possAdded++;
        	}
        }
    }

    cout << possAdded - alreadyPresent << "\n";
    return 0;
}
