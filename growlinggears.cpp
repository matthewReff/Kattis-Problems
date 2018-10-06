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
    
    ll cases;
    ll gears, a, b, c, maxGear;
    double temp;
    double max;
    double maxX;

    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> gears;
        max = 0;
        maxGear = 0;
        for (j = 0; j < gears; j++)
        {
            cin >> a >> b >> c;
            temp = -2.0 * a;
            maxX = -b / temp;
            if (max < -a * maxX * maxX + b * maxX + c)
            {
                max = -a * maxX * maxX + b * maxX + c;
                maxGear = j + 1;
            }
            
        }
        cout << maxGear << "\n";
    }
    return 0;

}

