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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll cases;
    ll totalTime;
    ll temp;
    ll customers;	
    ll projects;
    ll cumulativeTime;
    cin >> cases;
    
    cout << fixed << setprecision(10);
    for(i = 0; i < cases; i++)
    {
        cin >> customers;
        vector<ll> waitTimes(customers);
        for(j = 0; j < customers; j++)
        {
            cin >> projects;
            totalTime = 0;
            for(k = 0; k < projects; k++)
            {
                cin >> temp;
                totalTime += temp;
            }
            waitTimes[j] = totalTime;
        }
        sort(waitTimes.begin(), waitTimes.end());
        cumulativeTime = 0;
        totalTime = 0;
        for(j = 0; j < waitTimes.size(); j++)
        {
            totalTime += waitTimes[j] + cumulativeTime;
            cumulativeTime += waitTimes[j];
        }
        cout << totalTime / (ld)waitTimes.size() << "\n";
    }
    return 0;
}
