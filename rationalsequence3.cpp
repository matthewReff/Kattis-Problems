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
	ll cases, garb, num1, num2, num;
	char garbChar;

	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		cin >> garb >> num1;
		string navigate;
		ll numer = 1;
		ll denom = 1;
		while (num1 != 1)
		{
			if (num1 & 1)
			{
				navigate += '1';
			}
			else
			{
				navigate += '0';
			}
			num1 >>= 1;
		}
		reverse(navigate.begin(), navigate.end());
		for (auto bit : navigate)
		{
			if (bit == '1')
			{
				numer += denom;
			}
			else
			{
				denom += numer;
			}
		}
		cout << i + 1 << " " << numer << "/" << denom << "\n";
	}
	return 0;
}
