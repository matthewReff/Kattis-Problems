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
    ll n, q;
    map < ll, ll > locations; //<company, location>
    ll temp;
    ll comp, newLoc;
    ll op;

    cin >> n >> q;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        locations[i + 1] = temp;
    }

    for (i = 0; i < q; i++)
    {
        cin >> op;
        if (op == 1)

        {
            cin >> comp >> newLoc;
            locations[comp] = newLoc;
        }
        else
        {
            cin >> temp >> newLoc;
            cout << abs(locations[temp] - locations[newLoc]) << "\n";
        }
    }

    return 0;
}