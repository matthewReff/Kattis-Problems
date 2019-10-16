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

	ll nums;

	cin >> nums;
	ll lastVal = 1;
	ll val;
	set<ll> missed;
	for (i = 0; i < nums; i++)
	{
		cin >> val;
		for (j = lastVal; j < val; j++)
		{
			missed.insert(j);
		}
		lastVal = val + 1;
	}

	if (missed.size() != 0)
	{
		for (auto thing : missed)
		{
			cout << thing << "\n";
		}
	}
	else
	{
		cout << "good job\n";
	}
	return 0;
}