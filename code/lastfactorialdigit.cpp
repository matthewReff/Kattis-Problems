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
    ll cases, temp;
    cin >> cases;
    vector<int> factorials = { 1 };
    for (i = 1; i < 10; i++)
    {
        factorials.push_back(factorials[i - 1] * i);
    }


    for (i = 0; i < cases; i++)
    {
        cin >> temp;
        cout << factorials[temp] % 10 << "\n";
    }
    return 0;
}