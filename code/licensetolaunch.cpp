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

	ll days;
	ll min = 10000000000;
	cin >> days;

	vector<int> junk(days);
	for (i = 0; i < days; i++)
	{
		cin >> junk[i];
		if (junk[i] < min)
		{
			min = junk[i];
		}
	}
	
	for (i = 0; i < days; i++)
	{
		if (junk[i] == min)
		{
			cout << i  << "\n";
			return 0;
		}
	}
	return 0;
}
