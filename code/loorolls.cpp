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
using namespace std;

double GetDistance(pair<double, double> first, pair<double, double> second);
int GetRolls(ll l, ll n, ll rolls);

int main()
{
	ll l, n;
	cin >> l >> n;
	ll answer = GetRolls(l, n, 1);

	cout << answer << "\n";

	return 0;
}

int GetRolls(ll l, ll n, ll rolls)
{
	//cout << l << " " << n << " " << rolls << "\n";
	if (l % n == 0)
	{
		return rolls;
	}
	else
	{
		ll newN = n - (l % n);
		return GetRolls(l, newN, rolls + 1);
	}
}
double GetDistance(pair<double, double> first, pair<double, double> second)
{
	return sqrt(((first.first - second.first) * (first.first - second.first)) +
		((first.second - second.second) * (first.second - second.second)));
}