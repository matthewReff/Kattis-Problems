#define _USE_MATH_DEFINES
#include <iostream>
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


typedef long long ll;
using namespace std;

#define EPSILON 0.000001

int main()
{
    ll i, j, k;
    
    ll problems, first;
    ll temp, firstTime;
    ll totProb = 0;
    ll totPen = 0;
    ll totTime = 0;
    vector<ll> times;
    cin >> problems >> first;

    for (i = 0; i < problems; i++)
    {
        cin >> temp;
        if (i != first)
        {
            times.push_back(temp);
        }
        else
        {
            firstTime = temp;
        }
    }
    sort(times.begin(), times.end());

    if (totTime + firstTime > 300)
    {
        cout << totProb << " " << totPen << "\n";
        return 0;
    }
    else
    {
        totTime += firstTime;
        totProb++;
        totPen += firstTime;
    }
    for (i = 0; i < problems-1; i++)
    {
        if (totTime + times[i] <= 300)
        {
            totProb++;
            
            totPen += (totTime + times[i]);
            totTime += times[i];

        }
    }
    cout << totProb << " " << totPen << "\n";
    return 0;

}

