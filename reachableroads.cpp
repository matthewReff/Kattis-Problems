#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>

typedef long long ll;
using namespace std;

int main()
{

    ll i, j, k;
   
    ll cases, nodes, edges;
    ll source, dest, check;

    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> nodes >> edges;
        ll trees = 0;
        vector<vector<ll>> adj (nodes);
        vector<bool> seen (nodes, false);
        deque<ll> que;
        for (j = 0; j < edges; j++)
        {
            cin >> source >> dest;
            adj[source].push_back(dest);
            adj[dest].push_back(source);
        }
        for (j = 0; j < nodes; j++)
        {
            if (!seen[j])
            {
                que.push_back(j);
                trees++;
            }
            while (!que.empty())
            {
                check = que.front();
                que.pop_front();
                for (auto ez : adj[check])
                {
                    if (!seen[ez])
                    {
                        que.push_back(ez);
                        seen[ez] = true;
                    }
                }
            }
        }
        cout << trees - 1 << "\n";
    }
    


    return 0;
}
