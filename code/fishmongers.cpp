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
    
    ll n, m;
    ll monies = 0;
    cin >> n >> m;
    vector<ll> fishWeights(n);
    vector<pair<ll, ll>> mongers(m);
    for(i = 0; i < n; i++)
    {
        cin >> fishWeights[i];
    }
    
    sort(fishWeights.rbegin(), fishWeights.rend());
    
    for(i = 0; i < m; i++)
    {
        cin >> mongers[i].second >> mongers[i].first;
    }
    sort(mongers.rbegin(), mongers.rend());
    i = 0;
    j = 0;
    while(i < n)
    {
        monies += fishWeights[i] * mongers[j].first;
        mongers[j].second--;
        if(mongers[j].second == 0)
        {
            j++;
        }
        i++;
    }
    cout << monies << "\n";
    return 0;
}
