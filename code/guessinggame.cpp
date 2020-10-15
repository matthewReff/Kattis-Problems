#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
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
#include <unordered_set>
#include <bitset>

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
	int i, j, k;

	ll number;
	string command;
	string garbage, indicator;
	while (cin >> number && number != 0)
	{
		ll upperLimit = 11;
		ll lowerLimit = 0;
		cin >> garbage >> indicator;
		if (indicator == "high")
		{
			upperLimit = number;
		}
		else if (indicator == "low")
		{
			lowerLimit = number;
		}
		else
		{
			cout << "Stan may be honest\n";
			continue;
		}
		while (cin >> number >> garbage >> indicator && indicator != "on")
		{
			if (indicator == "low" && lowerLimit < number)
			{
				lowerLimit = number;
			}
			else if (indicator == "high" && upperLimit > number)
			{
				upperLimit = number;
			}
		}

		if (number >= upperLimit || number <= lowerLimit)
		{
			cout << "Stan is dishonest\n";
		}
		else
		{
			cout << "Stan may be honest\n";
		}
	}
	return 0;
}
