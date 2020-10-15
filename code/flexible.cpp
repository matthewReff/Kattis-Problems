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

    ll roomSize;
    ll dividers;

    cin >> roomSize >> dividers;

    set<ll> possibilies;
    set<ll> toAdd;
    vector<ll> values(dividers+2);
    values[values.size()-2] = 0;
    values[values.size()-1] = roomSize;

	for(i = 0; i < dividers; i++)
    {
    	cin >> values[i];
    }

    sort(values.begin(), values.end());

    for(i = 0; i < (int)values.size(); i++)
    {
    	for(j = i+1; j < (int)values.size(); j++)
    	{
    		possibilies.insert(values[j]-values[i]);
    	}
    }

    for(auto value : possibilies)
    {
    	if(value != 0)
    	{
    		cout << value << " ";
    	}
    }
    return 0;
}
//Start: Mon Jan 27 13:03:07 MST 2020
//Stop: Mon Jan 27 13:48:21 MST 2020
