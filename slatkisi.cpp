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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull i, j, k;
	int num, digits, temp;
	string numString;
	bool roundUp;
	cin >> num >> digits;
	if (digits != 0)
	{
		temp = num % int(pow(10, digits));
		if (temp >= int(pow(10, digits) / 2))
		{
			roundUp = true;
		}
		else
		{
			roundUp = false;
		}
		num -= temp;
		if (roundUp)
		{
			num += int(pow(10, digits));
		}
	}
	cout << num << "\n";
	return 0;
}
