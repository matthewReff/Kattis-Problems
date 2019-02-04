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

	ll nums, comp;
	ll index = -1;
	cin >> nums >> comp;
	vector<int> thing(nums);
	for (i = 0; i < nums; i++)
	{
		cin >> thing[i];
	}

	for (i = nums - 1; i >= 0; i--)
	{
		if (thing[i] <= comp)
		{
			index = i;
		}
	}

	if (index >= 0)
	{
		cout << "It hadn't snowed this early in " << index << " years!\n";
	}
	else
	{
		cout << "It had never snowed this early!\n";
	}
	return 0;
}
