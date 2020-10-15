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

	ll temp;
	ll teas;
	vector<ll> teaPrices;
	ll toppings;
	vector <ll> toppingsPrices;
	ll pairings;
	vector<vector<ll>> pairing2;
	ll money;
	ll leastCost = 1000000000;
	ll totalTeas;
	cin >> teas;

	for (i = 0; i < teas; i++)
	{
		cin >> temp;
		teaPrices.push_back(temp);
	}

	cin >> toppings;

	for (i = 0; i < toppings; i++)
	{
		cin >> temp;
		toppingsPrices.push_back(temp);
	}

	pairing2.resize(teas);

	for (i = 0; i < teas; i++)
	{
		cin >> pairings;
		for (j = 0; j < pairings; j++)
		{
			cin >> temp;
			pairing2[i].push_back(temp);
		}
	}

	for (i = 0; i < teas; i++)
	{
		for (auto x : pairing2[i])
		{
			if (teaPrices[i] + toppingsPrices[x - 1] < leastCost)
			{
				leastCost = teaPrices[i] + toppingsPrices[x - 1];
			}
		}
	}
	cin >> money;
	totalTeas = money / leastCost - 1;
	if (totalTeas <= 0)
	{
		cout << "0\n";
	}
	else
	{
		cout << totalTeas << "\n";
	}
	return 0;
}