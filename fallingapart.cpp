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

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	
	ll nums;
	ll sum1 = 0;
	ll sum2 = 0;
	cin >> nums;
	vector<ll> numList(nums);

	for (i = 0; i < nums; i++)
	{
		cin >> numList[i];
	}

	sort(numList.rbegin(), numList.rend());

	for (i = 0; i < nums; i++)
	{
		if (i % 2 == 0)
		{
			sum1 += numList[i];
		}
		else
		{
			sum2 += numList[i];
		}
	}
	cout << sum1 << " " << sum2 << "\n";
	return 0;
}


