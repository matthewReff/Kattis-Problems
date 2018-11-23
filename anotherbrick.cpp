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
using namespace std;

int main()
{
    ll i, j, k;
    ll height, width, bricks;

    ll currHeight = 0;
    cin >> height >> width >> bricks;
    ll currWidth = width;
    vector<ll> lengths(bricks);
    for (i = 0; i < bricks; i++)
    {
        cin >> lengths[i];
    }
    i = 0;
    while (bricks)
    {

        if (currWidth == 0)
        {
            currWidth = width;
            currHeight++;
        }
        if (currWidth - lengths[i] >= 0)
        {
            currWidth -= lengths[i];
            bricks--;
            i++;
        }
        else
        {
            bricks = 0;
        }

    }

    if (currWidth == 0)
    {
    //    currWidth = width;
        currHeight++;
    }

    if (currHeight >= height)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}