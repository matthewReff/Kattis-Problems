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

void hail(ll input, ll currentSum)
{
	if(input == 1)
	{
		cout << 1 + currentSum << "\n";
	}
	else if(input % 2 == 0)
	{
		hail(input/2, currentSum+input);
	}
	else
	{
		hail(input*3+1, currentSum+input);
	}
}

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll initial;
    cin >> initial;
    cout << fixed;
    hail(initial, 0);
    return 0;
}
//Start: Sat Feb 1 10:52:49 MST 2020
