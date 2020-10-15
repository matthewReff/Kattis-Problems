#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

typedef long long ll;
using namespace std;

int main()
{

    long long i, j, k;

    string stoneString;
    ll blackSum = 0;
    ll whiteSum = 0;
    cin >> stoneString;

    for (auto stone : stoneString)
    {
        if (stone == 'W') 
        {
            whiteSum++;
        }
        else
        {
            blackSum++;
        }
    }

    cout << int(stoneString.size() % 2 == 0 && blackSum == whiteSum);

    return 0;
}