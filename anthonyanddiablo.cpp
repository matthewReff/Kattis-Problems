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
    ld a, n, temp;
    cin >> a >> n;
    temp = n / M_PI / 2;
    temp = temp * temp * M_PI;
    if (temp > a)
    {
        cout << "Diablo is happy!\n";
    }
    else
    {
        cout << "Need more materials!\n";
    }
    return 0;
}