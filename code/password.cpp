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
typedef long double ld;
using namespace std;

int main()
{
    ll i, j, k;
    ll cases;
    string password;
    ld freq;
    ld total = 0.0;
    vector<double > vals;
    cin >> cases;
    
    for(i = 0; i < cases; i++)
    {
       cin >> password >> freq;
       vals.push_back(freq);
    }
    sort(vals.rbegin(), vals.rend());
    for(i = 0; i < vals.size(); i++)
    {
        total += (i+1) * vals[i];
    }
    cout << fixed << setprecision(10);
    cout << total << "\n";
    return 0;
}
