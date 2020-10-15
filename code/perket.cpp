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
    ull i, j, k;
    
    ll numPairs;
    ll garb, biggestNum, temp;
    ll num1, num2;
    ll sourness, bitterness;
    string numString;
    vector<pair<ll, ll> > ingreds;
    cin >> numPairs;

    for (i = 0; i < numPairs; i++)
    {
        cin >> num1 >> num2;
        ingreds.push_back(make_pair(num1, num2));
    }

    ll smallestDiff = 1000000000;
    for (i = 1; i < pow(2, numPairs); i++)
    {
        sourness = 1;
        bitterness = 0;
        for (j = 0; j < numPairs; j++)
        {
            if (((i >> j) & 1))
            {
                sourness *= ingreds[j].first;
                bitterness += ingreds[j].second;
            }
        }
        smallestDiff = min(smallestDiff, abs(sourness - bitterness));
        
    }
    cout << smallestDiff << "\n";
    return 0;
}
