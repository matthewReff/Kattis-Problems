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

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;

	ll cases;
	ll num;

	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		cin >> num >> num;
		cout << i + 1 << " " << ((num * (num + 1)) / 2) + num << "\n";
	}
	return 0;
}
