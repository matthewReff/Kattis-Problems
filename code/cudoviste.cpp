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
	ll i, j, k, l;
	
	ll r, c;
	vector<string> city;
	string cityString;
	ll carCount = 0;
	ll buildingCount = 0;
	ll carNums[5] = { 0,0,0,0,0 };
	cin >> r >> c;
	
	for (i = 0; i < r; i++)
	{
		cin >> cityString;
		city.push_back(cityString);
	}

	for (i = 0; i < r - 1; i++)
	{
		for (j = 0; j < c - 1; j++)
		{
			buildingCount = 0;
			carCount = 0;
			for (k = 0; k < 2; k++)
			{
				for (l = 0; l < 2; l++)
				{
					if (city[i + k][j + l] == '#')
					{
						buildingCount++;
					}
					else if (city[i + k][j + l] == 'X')
					{
						carCount++;
					}
				}
			}
			if (buildingCount == 0)
			{
				carNums[carCount]++;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		cout << carNums[i] << "\n";
	}
	return 0;
}