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

	ll num;
	ll diff1;
	ll diff2;
	vector <ll> theVec;
	for (i = 0; i < 3; i++)
	{
		cin >> num;
		theVec.push_back(num);
	}

	sort(theVec.begin(), theVec.end());

	diff1 = theVec[1] - theVec[0];

	diff2 = theVec[2] - theVec[1];
	if (diff1 == 0 || diff2 == 0)
	{
		cout << theVec[0];
	}
	else if (diff1 / diff2 != 1)
	{
		if (abs(diff1) - abs(diff2) > 0)
		{
			cout << diff2 + theVec[0];
		}
		else
		{
			cout << diff1 + theVec[1];
		}
	}
	else
	{
		cout << theVec[2] + diff1;
	}
	return 0;
}