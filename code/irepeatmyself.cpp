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

    ll first, second, temp;
    ll cases;
    string inString;
    cin >> cases;
    cin.ignore();
    for (i = 0; i < cases; i++)
    {
        first = 0;
        getline(cin, inString);
        for (second = 1; second < inString.size(); second++)
        {
            if (inString[first] == inString[second])
            {
                first++;
            }
            else
            {
                second = second - first;
                first = 0;
            }
        }
        cout << second - first << "\n";
    }

    return 0;
}