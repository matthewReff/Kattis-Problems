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
    ll loops, start, stop;
    ll days = 0;
    vector<bool> food(366, false);
    cin >> loops;
    

    for (i = 0; i < loops; i++)
    {
        cin >> start >> stop;
        for (j = start; j <= stop; j++)
        {
            food[j] = true;
        }
    }
    
    for (i = 0; i < 366; i++)
    {
        if (food[i])
        {
            days++;
        }
    }
    cout << days << "\n";
    return 0;
}
