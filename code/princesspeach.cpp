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
    ll obstacles, found, temp;
    set < ll > uniques;
    set<ll>::iterator itr;
    cin >> obstacles >> found;
    for (i = 0; i < found; i++)
    {
        cin >> temp;
        uniques.insert(temp);
    }

    for (i = 0; i < obstacles; i++)
    {
        if (uniques.find(i) == uniques.end())
        {
            cout << i << "\n";
        }
    }

    cout << "Mario got " << uniques.size()
        << " of the dangerous obstacles.\n";
    return 0;
}