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
    ll garb, biggestNum, temp;
    string numString;

    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> garb >> numString;
        biggestNum = 0;
        for (j = 0; j < numString.size(); j++)
        {
           temp = numString[j] - '0';
           biggestNum = max(biggestNum, temp);
        }
        cout << i + 1 << " ";
        if (biggestNum >= 8)
        {
            cout << "0 ";
        }
        else
        {
            cout << stoi(numString, NULL, 8) << " ";
        }
        cout << stoi(numString, NULL, 10) << " ";
        cout << stoi(numString, NULL, 16) << "\n";
    }
    return 0;
}
