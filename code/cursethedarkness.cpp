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
    
    ll cases;
    ld bookX, bookY, candleX, candleY;
    ll candles;
    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        bool valid = false;
        cin >> bookX >> bookY >> candles;
        for (j = 0; j < candles; j++)
        {
            cin >> candleX >> candleY;
            valid |= sqrt((candleX - bookX) * (candleX - bookX) + 
                (candleY - bookY) * (candleY - bookY)) <= 8;
        }
        if (valid)
        {
            cout << "light a candle\n";
        }
        else
        {
            cout << "curse the darkness\n";
        }
        
    }
    return 0;
}
