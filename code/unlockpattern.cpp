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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pair<ll, ll>> coords(9);

    for(i = 0; i < 3; i++)
    {
    	for(j = 0; j < 3; j++)
    	{
    		ll val;
    		cin >> val;
    		coords[val-1] = make_pair(i, j);
    	}
    }

    double total = 0;
    for(i = 0; i < 8; i++)
    {
    	total += sqrt(abs(coords[i].first - coords[i+1].first) * abs(coords[i].first - coords[i+1].first) + 
    	abs(coords[i].second - coords[i+1].second) * abs(coords[i].second - coords[i+1].second));
    }
    cout << fixed << setprecision(10);
    cout << total << "\n";
    return 0;
}
