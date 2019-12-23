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

    ll nums;
    ll interval, start;
    map<ll, ll> points;
    cin >> nums;

    for(i = 0; i < nums; i++)
    {
    	cin >> interval >> start;
    	points[start]++;
    	points[start-interval]++;
    	points[start-interval-interval]++;
    }

    ll maxVal = 0;
    for(auto thing : points)
    {
    	ll value = thing.second;
    	maxVal = max(maxVal, value); 
    }

    cout << ceil(maxVal / 2.0) << "\n";

    return 0;
}
