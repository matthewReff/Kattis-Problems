#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k;

	ll jackCD, jillCD;
	ll cd;
	ll totalCDS;
	bool * jackCDS;
	bool * jillCDS;

	jackCDS = new(nothrow) bool[10000001];
	jillCDS = new(nothrow) bool[10000001];

	cin >> jackCD >> jillCD;

	while (jackCD != 0 && jillCD != 0)
	{
		totalCDS = 0;
		for (i = 0; i < 10000001; i++)
		{
			jackCDS[i] = false;
			jillCDS[i] = false;
		}

		for (i = 0; i < jackCD; i++)
		{
			cin >> cd;
			jackCDS[cd] = true;
		}

		for (i = 0; i < jillCD; i++)
		{
			cin >> cd;
			jillCDS[cd] = true;
		}

		for (i = 0; i < 10000001; i++)
		{
			if (jackCDS[i] && jillCDS[i])
			{
				totalCDS++;
			}
		}
		cout << totalCDS << "\n";
		cin >> jackCD >> jillCD;
	}
	return 0;
}