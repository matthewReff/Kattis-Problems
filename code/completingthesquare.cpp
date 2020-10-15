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
    char common;
    pair < ll, ll> A;
    pair < ll, ll> B;
    pair < ll, ll> C;

    pair <ll, ll> AB;
    pair <ll, ll> AC;
    pair <ll, ll> BC;
    pair <ll, ll> temp;
    ld magAB;
    ld magAC;
    ld magBC;
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;

    AB.first = B.first - A.first;
    AB.second = B.second - A.second;

    AC.first = C.first - A.first;
    AC.second = C.second - A.second;

    BC.first = C.first - B.first;
    BC.second = C.second - B.second;

    magAB = sqrt(AB.first * AB.first + AB.second * AB.second);
    magAC = sqrt(AC.first * AC.first + AC.second * AC.second);
    magBC = sqrt(BC.first * BC.first + BC.second * BC.second);

    if (fabs(magAB - magAC) < 0.0001)
    {
        common = 'A';
    }
    else if (fabs(magAB - magBC) < 0.0001)
    {
        common = 'B';
    }
    else if (fabs(magBC - magAC) < 0.0001)
    {
        common = 'C';
    }

    if (common == 'A')
    {
        temp.first = B.first - A.first;
        temp.second = B.second - A.second;
        temp.first += C.first;
        temp.second += C.second;
        //apply ab to c
    }
    else if (common == 'B')
    {
        temp.first = A.first - B.first;
        temp.second = A.second - B.second;
        temp.first += C.first;
        temp.second += C.second;
        //apply ba to c
    }
    else if (common == 'C')
    {
        temp.first = A.first - C.first;
        temp.second = A.second - C.second;
        temp.first += B.first;
        temp.second += B.second;
        //apply ca to b
    }
    cout << temp.first << " " << temp.second << "\n";
    return 0;
}