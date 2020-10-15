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
#include <map>
#include <set>

using namespace std;
typedef long long ll;

bool dfs(int curr, vector<vector<ll> >  & adj, vector<bool>  & seen, ll end);

int main()
{
	ll i, j, k;
	string pergram;
	map<char, ll> charMap;
	ll neededChanges  = 0;
	ll totalChanges = 0;
	bool found = false;
	cin >> pergram;

	for (auto testChar : pergram)
	{
		charMap[testChar]++;
	}

	for (auto mappyBit : charMap)
	{
		neededChanges += mappyBit.second % 2;
	}

	for (i = 1; !found && i < neededChanges; i++)
	{
		totalChanges++;
		if ((neededChanges - i) % 2 == 1)
		{
			if (neededChanges - i - 1 == 0)
			{
				found = true;
			}
		}
		else
		{
			if (neededChanges - i == 0)
			{
				found = true;
			}
		}
	}
	cout << totalChanges;

	return 0;
}




