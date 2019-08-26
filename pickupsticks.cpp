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
    ll top, bottom;
    ll numSticks, entries;
    ll removed = 0;
    
    cin >> numSticks >> entries;
    vector<pair<ll, ll>> edgeDegrees(numSticks);
    vector<vector<ll>> adj(numSticks);
    vector<bool> used(numSticks, false);
    vector<ll> removedSticks;
    for(i = 0; i < entries; i++)
    {
        cin >> top >> bottom;
        top--;
        bottom--;
        adj[top].push_back(bottom);
        edgeDegrees[top].second++;
        edgeDegrees[bottom].first++;
    }
    
    /*
    cout << "\n";
    for(auto thing : edgeDegrees)
    {
        cout << thing.first << " " << thing.second << "\n";
    }
    */
    
    for(i = 0; i < numSticks; i++)
    {
        if(!used[i] && edgeDegrees[i].first == 0)
        {
            removedSticks.push_back(i+1);
            removed++;
            used[i] = true;
            
            deque<ll> q;
            q.push_back(i);
            while(q.size())
            {
                ll front = q.front();
                q.pop_front();
                for(auto thing : adj[front])
                {
                    edgeDegrees[thing].first--;
                    if(edgeDegrees[thing].first == 0)
                    {
                        q.push_back(thing);
                        removedSticks.push_back(thing+1);
                        removed++;
                        used[thing] = true;
                    }
                }
            }
        }   
    }
    
    if(removed == numSticks)
    {
        for(auto thing : removedSticks)
        {
            cout << thing << "\n";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
