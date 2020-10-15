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
    ll items, price;

    cin >> items >> price;

    vector<ll> itemPrices(items);
    for(i = 0; i < items; i++)
    {
    	cin >> itemPrices[i];
    }
    
    sort(itemPrices.begin(), itemPrices.end());

    ll possible = 1;
    for(i = 1; i < items; i++)
    {
    	if(itemPrices[i-1] + itemPrices[i] <= price)
    	{
    		possible++;
    	}
    }

    cout << possible << "\n";
    return 0;
}
