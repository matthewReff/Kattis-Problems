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
	
	ll cases;
	ll temp;
	ll lastClean = 0;
	ll cleans = 0;
	vector<ll> pushes;
	vector<ll> tempPushes;
	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		cin >> temp;
		pushes.push_back(temp);
	}

	for (i = 0; i < cases; i++)
	{
		temp = 0;
		for (j = 0; j < tempPushes.size(); j++)
		{
			temp += pushes[i] - lastClean - tempPushes[j];
			
		}

		if (temp < 20)
		{
			tempPushes.push_back(pushes[i] - lastClean);
		}
		else
		{
			lastClean = pushes[i];
			cleans++;
			tempPushes.clear();
			tempPushes.push_back(pushes[i] - lastClean);
		}
	}
	cout << cleans + 1 << "\n";
	return 0;
}



