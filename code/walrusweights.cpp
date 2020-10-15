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

    ll numWeights;
    cin >> numWeights;
    ll closestOver = 2001;
    ll amount;
    set<ll> possibles;
    for(i = 0; i < numWeights; i++)
    {
    	cin >> amount;
    	set<ll> toAdd;
    	for(auto value : possibles)
    	{
    		ll newVal = value + amount;
    		if(newVal < closestOver)
    		{
    			toAdd.insert(newVal);
    			if(newVal >= 1000)
    			{
    				closestOver = newVal;
    			}
    		}
    	}
    	toAdd.insert(amount);
    	possibles.insert(toAdd.begin(), toAdd.end());
    }

    ll closest = 2001;
    ll diff = 1000;
    for(auto thing : possibles)
    {
    	//cout << thing << "\n";
    	if(abs(thing - 1000) <= diff)
    	{
    		diff = abs(thing - 1000);
    		closest = thing;
    	}
    }

    cout << closest << "\n";
    return 0;
}
//started: 1:20