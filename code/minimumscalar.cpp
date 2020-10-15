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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    
    ll cases;
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
    	ll values;
    	cin >> values;
    	vector<ll> first(values);
    	vector<ll> second(values);
    	for(j = 0; j < values; j++)
    	{
    		cin >> first[j];
    	}
    	for(j = 0; j < values; j++)
    	{
    		cin >> second[j];
    	}
    	sort(first.begin(), first.end());
    	sort(second.rbegin(), second.rend());
    	ll sum = 0;
    	for(j = 0; j < values; j++)
    	{
    		sum += first[j] * second[j];
    	}
    	cout << "Case #" << i+1 << ": " << sum << "\n";
    }
    return 0;
}
