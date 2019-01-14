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
    ll x, y;
    ll cases;
    ll sideLength, numHatches;
    ld allowedDistance;
    ld hatchDistance;
    bool possible = true;
    
    cin >> cases;
    for(i = 0; i < cases; i++)
    {
        cin >> sideLength >> numHatches;
        vector<pair<ll, ll> > hatchCoordVec;
        for(j = 0; j < numHatches; j++)
        {
            cin >> x >> y;
            hatchCoordVec.push_back(make_pair(x, y));
        }
        
        possible = false;
        for(j = 0; j < sideLength && !possible; j++)
        {
            for(k = 0; k < sideLength && !possible; k++)
            {
                allowedDistance = min(min(j,sideLength - j),min(k,sideLength - k));
                possible = true;
                for(ll l = 0; l < numHatches; l++)
                {
                    hatchDistance = sqrt((hatchCoordVec[l].first - j) * (hatchCoordVec[l].first - j) 
                    +  (hatchCoordVec[l].second - k) * (hatchCoordVec[l].second - k));
                    if (hatchDistance > allowedDistance)
                    {
                        possible = false;
                    }
                }
                if(possible)
                {
                    if(find(hatchCoordVec.begin(), hatchCoordVec.end(), make_pair(j, k)) 
                    != hatchCoordVec.end())
                    {
                        possible = false;
                    }
                    else
                    {
                        cout << j << " " << k << "\n";
                    }
                }   
            }
        }
        if (!possible)
        {
            cout << "poodle\n";
        }
    }
    return 0;
}
