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

    ll numbers, divisor;
    cin >> numbers >> divisor;
    unordered_map<ll, ll> mods;

    ll temp;
    for(i = 0; i < numbers; i++)
    {
    	cin >> temp;
    	mods[temp/divisor]++;
    }

    ll total = 0;
    for(auto thing : mods)
    {
    	total += ((thing.second) * (thing.second - 1)) / 2;
    }

    cout << total << "\n";
    return 0;
}
