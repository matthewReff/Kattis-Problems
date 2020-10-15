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
#include <stack>
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
    ll i, j, k;
    ll total = 0;
    
    vector<ll> registers(8);
    vector<ll> values = {1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690};
    for(i = 0; i < 8; i++)
    {
        cin >> registers[i];
    }
    
    for(i = 0; i < 8; i++)
    {
        total += registers[i] * values[i];
    }
    
    cout << 9699689 - total << "\n";
    return 0;
}
