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
    ll x, y, x1, y1, x2, y2;
    ld answer;
    cin >> x >> y >>x1 >> y1 >> x2 >> y2;
    ll xdist, ydist;
    
    if (x > x1 && x2 > x)
    {
        xdist = 0;
    }
    else if(x < x1)
    {
        xdist = x - x1;
    }
    else
    {
        xdist = x2 - x;
    }
    
    if (y > y1 && y2 > y)
    {
        ydist = 0;
    }
    else if(y < y1)
    {
        ydist = y - y1;
    }
    else
    {
        ydist = y2 - y;
    }
    
    answer = sqrt(xdist * xdist + ydist * ydist);
    cout << fixed << setprecision(5);
    cout << answer << "\n";
    return 0;
}
