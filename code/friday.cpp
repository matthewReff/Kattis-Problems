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

typedef long long ll;
using namespace std;

int main()
{

    ll i, j, k;

    
    ll cases, months, days, currDay;
    ll day;
    ll total;

    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> months >> days;
        currDay = -1;
        total = 0;
        for (j = 0; j < days; j++)
        {
            cin >> day;
            if (day > 12)
            {
                if ((currDay + 13) % 7 == 5)
                {
                    total++;
                }
                currDay = ((currDay + day) % 7);
            }
            else
            {
                currDay = (currDay + day % 7);
            }
        }
        cout << total << "\n";
    }
    
    return 0;
}