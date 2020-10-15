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
	ll n;
	long double e = 0.0;
	ll factorial[15] = { 1 };
	for (i = 1; i < 15; i++)
	{
		factorial[i] = i * factorial[i - 1];
	}
	cin >> n;
	if (n < 15)
	{
		for (i = 0; i <= n; i++)
		{
			e += 1.0 / factorial[i];
		}
		cout << fixed << setprecision(15);
		cout << e << "\n";
	}
	else
	{
		cout << "2.718281828458995\n";
	}
	return 0;
}
