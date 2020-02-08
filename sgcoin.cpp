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

    ll initial;
    ll modVal = 1000000007;
    cin >> initial;

    for(i = 0; i < 2; i++)
    {
    ll val = initial * 31 + 'a';
    val %= modVal;

    val *= 7;
    val %= modVal;
    ll token = 10000000 - (val % 10000000);

    cout << 'a' << " " << token << "\n";
    initial = (val + token) % modVal;
    //cout << initial << "\n";
	}
    
    return 0;
}
