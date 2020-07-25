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
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll lights, roadLength;
    cin >> lights >> roadLength;

    vector<ll> dists;
    vector<ll> reds;
    vector<ll> greens;
    ll dist, red, green;
    for (i = 0; i < lights; i++)
    {	
    	cin >> dist >> red >> green;
    	dists.push_back(dist);
    	reds.push_back(red);
    	greens.push_back(green);
    }

    ll totalTime = 0;
    ll currentLoc = 0;
    for(i = 0; i < lights; i++)
    {
    	ll period = reds[i] + greens[i];
    	totalTime += dists[i] - currentLoc;
    	currentLoc = dists[i];
    	if(totalTime % period < reds[i])
    	{
    		totalTime += reds[i] - totalTime % period;
    	}
    }

    totalTime += roadLength - currentLoc;

    cout << totalTime << "\n";
    return 0;
}
