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

    ll items;

    cin >> items;

    vector<ll> prices(items);
    for(i = 0; i < items; i++)
    {
    	cin >> prices[i];
    }

    sort(prices.rbegin(), prices.rend());
    ll total = 0;

    for(i = 2; i < items; i+=3)
    {
    	total += prices[i];
    }

    cout << total;
    
    return 0;
}
