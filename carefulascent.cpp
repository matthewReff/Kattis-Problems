#define _USE_MATH_D77EFINES
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

	vector<vector<ll>> shields;
	vector<double> modifiers;
	double xCoord, yCoord;
	ll num;
	ll num1, num2;
	double modifier;
	ll currAlt = 0;
	double dist = 0.0;
	cin >> xCoord >> yCoord;

	cin >> num;
	shields.resize(num);
	cout << fixed << setprecision(11);
	for (i = 0; i < num; i++)
	{
		cin >> num1 >> num2;
		cin >> modifier;
		shields[i].push_back(num1);
		shields[i].push_back(num2);
		shields[i].push_back(i);
		modifiers.push_back(modifier);
	}
	sort(shields.begin(), shields.end());

	for (j = 0; j < num; j++)
	{
		dist += shields[j][0] - currAlt;
		currAlt = shields[j][1];
		dist += ((shields[j][1] - shields[j][0]) * modifiers[shields[j][2]]);
	}

	dist += yCoord - currAlt;

	cout << xCoord / dist << "\n";
	return 0;
}