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

    ll s, t, n;
    cin >> s >> t >> n;
    vector<ll> times(n+1);
    vector<ll> busTimes(n);
    vector<ll> intervals(n);

    for(i = 0; i < n+1; i++)
    	cin >> times[i];

    for(i = 0; i < n; i++)
    	cin >> busTimes[i];

    for(i = 0; i < n; i++)
    	cin >> intervals[i];

    ll currentTime = s;
    for(i = 0; i < n; i++)
    {
    	currentTime += times[i];
    	//cout << "after walk: " << currentTime << "\n";

    	ll modVal = currentTime % intervals[i];
    	if (modVal != 0)
    		currentTime += intervals[i] - modVal;
    	//cout << "after bus wait: " << currentTime << "\n";

    	currentTime += busTimes[i];
    	//cout << "after bus: " << currentTime << "\n";
    }
    currentTime += times[n];

    if(currentTime > t)
    	cout << "no\n";
    else
    	cout << "yes\n";
    return 0;
}
