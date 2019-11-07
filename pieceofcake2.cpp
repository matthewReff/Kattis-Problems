#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll sideLen, cut1, cut2;

    cin >> sideLen >> cut1 >> cut2;

    ll max1, max2;
    max1 = max(sideLen-cut1, cut1);
    max2 = max(sideLen-cut2, cut2);

    cout << max1 * max2 * 4 << "\n";
    return 0;
}
