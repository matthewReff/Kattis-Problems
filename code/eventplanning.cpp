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
	ll people, budget, hotels, weeks;
	ll roomCost, capacity, max, temp;
	vector<ll> possibles;

	cin >> people >> budget >> hotels >> weeks;

	for (i = 0; i < hotels; i++)
	{
		cin >> roomCost;
		max = 0;
		for (j = 0; j < weeks; j++)
		{
			cin >> capacity;
			if (capacity > max)
			{
				max = capacity;
			}
		}
		if (max >= people)
		{
			possibles.push_back(roomCost);
		}
	}

	sort(possibles.begin(), possibles.end());

	if (possibles.size() != 0 && possibles[0] * people <= budget)
	{
		cout << possibles[0] * people << "\n";
	}
	else
	{
		cout << "stay home\n";
	}
	return 0;
}
