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
	double distance;
	int toNext;
	int cases;
	int letter;
	double tileLength = 60 * M_PI / 28;
	vector<int> tileNums;
	string track = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '";
	string aphorism;
	cin >> cases;
	cin.ignore();

	for (i = 0; i < cases; i++)
	{
		cout << fixed << setprecision(10);
		tileNums.clear();
		distance = 0;
		getline(cin, aphorism);
		for (j = 0; j < aphorism.size(); j++)
		{
			for (k = 0; k < 28; k++)
			{
				if (track[k] == aphorism[j])
				{
					tileNums.push_back(k);
				}
			}
			
		}
		for (j = 0; j < tileNums.size() - 1; j++)
		{
			if (28 - abs(tileNums[j + 1] - tileNums[j]) >
				abs(tileNums[j + 1] - tileNums[j]))
			{
				toNext = abs(tileNums[j + 1] - tileNums[j]);
			}
			else
			{
				toNext = 28 - abs(tileNums[j + 1] - tileNums[j]);
			}
			distance += (toNext * tileLength / 15);
			
		}
		distance += tileNums.size();
		cout << distance << "\n";
	}

	return 0;
}