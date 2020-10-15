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

	ll n;
	ll person;
	map<int, int> lastSeen;
	map<int, int> furthestDistance;
	map<int, int>::iterator itr;
	cin >> n;
	ll awkwardness = n;

	for (i = 0; i < n; i++)
	{
		cin >> person;
		if (lastSeen.find(person) != lastSeen.end())
		{
			if (furthestDistance.find(person) != furthestDistance.end())
			{
				if (furthestDistance[person] > i - lastSeen[person])
				{
					furthestDistance[person] = i - lastSeen[person];
				}
			}
			else
			{
				furthestDistance[person] = i - lastSeen[person];
			}
		}
		lastSeen[person] = i;
	}

	itr = furthestDistance.begin();
	while (itr != furthestDistance.end())
	{
		if (itr->second < awkwardness)
		{
			awkwardness = itr->second;
		}
		itr++;
	}
	
	if (awkwardness == n)
	{
		cout << n << "\n";
	}
	else
	{
		cout << awkwardness << "\n";
	}
	return 0;
}
