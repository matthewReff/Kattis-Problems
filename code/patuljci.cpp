#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;


int main()
{
	long long i, j, k;
	
	int dwarves[9];
	bool exclude[9];
	int sum = 0;

	for (i = 0; i < 9; i++)
	{
		cin >> dwarves[i];
		sum += dwarves[i];
		exclude[i] = true;
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j != i)
			{
				if (sum - dwarves[i] - dwarves[j] == 100)
				{
					exclude[i] = false;
					exclude[j] = false;
				}
			}
		}
	}
	for (i = 0; i < 9; i++)
	{
		if (exclude[i])
		{
			cout << dwarves[i] << "\n";
		}
	}
	return 0;
}