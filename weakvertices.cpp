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
    ull i, j, k;


    ll n;
    bool temp;
    bool valid1, valid2, valid3;
    vector<vector<bool>> adj;
    while (cin >> n && n != -1)
    {
        vector<bool> weak(n, true);
        adj.resize(n);
        for (i = 0; i < n; i++)
        {
            adj[i].resize(n);
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> temp;
                adj[i][j] = temp;
            }
        }


        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                for (k = j + 1; k < n; k++)
                {
                    valid1 = adj[i][j];
                    valid2 = adj[j][k];
                    valid3 = adj[i][k];
                    if (valid1 && valid2 && valid3)
                    {
                        weak[i] = false;
                        weak[j] = false;
                        weak[k] = false;
                    }
                }
            }
        }


        for (i = 0; i < n; i++)
        {
            if (weak[i])
            {
                cout << i << " ";
            }
        }
        cout << "\n";

    }


    return 0;
}
