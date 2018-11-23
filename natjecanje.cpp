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
using namespace std;

int main()
{
	ll i, j, k;
	ll teams, damaged, reserve;
	ll temp;
	ll invalids = 0;
	cin >> teams >> damaged >> reserve;
	vector<bool> damagedIndex(teams);
	vector<bool> reserveIndex(teams);

	for (i = 0; i < damaged; i++)
	{
		cin >> temp;
		damagedIndex[temp - 1] = true;
	}
	for (i = 0; i < reserve; i++)
	{
		cin >> temp;
		reserveIndex[temp - 1] = true;
	}

	for (i = 0; i < teams; i++)
	{
		if (damagedIndex[i])
		{
			if (i != 0 && reserveIndex[i - 1])
			{
				reserveIndex[i - 1] = false;
			}
			else if (i != teams - 1 && reserveIndex[i + 1])
			{
				reserveIndex[i + 1] = false;
			}
			else
			{
				invalids++;
			}
		}			
	}
	cout << invalids << "\n";
	return 0;
}
