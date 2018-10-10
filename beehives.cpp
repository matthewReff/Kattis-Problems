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
#include <map>
#include <numeric>
#include <set>

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	
	double dist;
	double tempDist;
	ll hives;
	ll totalSours;

	while (cin >> dist >> hives && dist != 0.0 && hives != 0)
	{
		totalSours = 0;
		vector<bool> sours(hives, false);
		vector<pair<double, double>> coords(hives);
		for (i = 0; i < hives; i++)
		{
			cin >> coords[i].first;
			cin >> coords[i].second;
		}
		for (i = 0; i < hives; i++)
		{
			for (j = i + 1; j < hives; j++)
			{
				tempDist = sqrt((coords[i].first - coords[j].first) *
					(coords[i].first - coords[j].first) +
					(coords[i].second - coords[j].second) *
					(coords[i].second - coords[j].second));
				if (tempDist < dist)
				{
					sours[i] = true;
					sours[j] = true;
				}
			}
		}
		for (i = 0; i < hives; i++)
		{
			if (sours[i])
			{
				totalSours += 1;
			}
		}
		cout << totalSours << " sour, " << hives - totalSours << " sweet\n";
	}
}


