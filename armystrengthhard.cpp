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

	ll cases, size1, size2, num;

	vector<ll> god;
	vector<ll> mechaGod;

	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		god.clear();
		mechaGod.clear();
		cin >> size1 >> size2;

		for (j = 0; j < size1; j++)
		{
			cin >> num;
			god.push_back(num);
		}
		for (j = 0; j < size2; j++)
		{
			cin >> num;
			mechaGod.push_back(num);
		}
		sort(god.rbegin(), god.rend());

		sort(mechaGod.rbegin(), mechaGod.rend());

		while (god.size() != 0 && mechaGod.size() != 0)
		{
			if (god.back() >= mechaGod.back())
			{
				mechaGod.pop_back();
			}
			else
			{
				god.pop_back();
			}
		}
		if (god.size() != 0 && mechaGod.size() == 0)
		{
			cout << "Godzilla\n";
		}
		else if (mechaGod.size() != 0 && god.size() == 0)
		{
			cout << "MechaGodzilla\n";
		}
		else
		{
			cout << "uncertain\n";
		}
		
	}

	return 0;
}