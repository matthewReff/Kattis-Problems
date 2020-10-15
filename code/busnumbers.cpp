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

typedef long long ll;
using namespace std;

int main()
{
	ll i, j, k;

	ll buses;
	cin >> buses;
	vector<ll> busList(buses);
	vector<ll> littleList;

	for (i = 0; i < buses; i++)
	{
		cin >> busList[i];
	}
	sort(busList.begin(), busList.end());

	for (i = 0; i < busList.size(); i++)
	{
		
		if (littleList.size() == 0)
		{
			littleList.push_back(busList[i]);
		}
		else if (i + 1 <= busList.size() && (littleList[littleList.size()-1] + 1) == busList[i])
		{
			littleList.push_back(busList[i]);
		}
		
		else
		{
			if (littleList.size() < 3)
			{
				for (j = 0; j < littleList.size(); j++)
				{
					cout << littleList[j] << " ";
				}
			}
			else
			{
				cout << littleList[0] << "-" << littleList[littleList.size() - 1] << " ";
			}
			littleList.clear();
			littleList.push_back(busList[i]);
		}
		if (i == busList.size() - 1)
		{
			if (littleList.size() < 3)
			{
				for (j = 0; j < littleList.size(); j++)
				{
					cout << littleList[j] << " ";
				}
			}
			else
			{
				cout << littleList[0] << "-" << littleList[littleList.size() - 1] << " ";
			}
		}
	}
	return 0;
}

