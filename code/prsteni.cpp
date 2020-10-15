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

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	ll i, j, k;
	
	ll cases;
	ll base;
	ll temp;
	cin >> cases;
	vector<ll> nums(cases);

	for (i = 0; i < cases; i++)
	{
		cin >> nums[i];
		
	}
	base = nums[0];

	for (i = 1; i < cases; i++)
	{
		temp = gcd(base, nums[i]);
		cout << base / temp << "/" << nums[i] / temp << "\n";
	}
	return 0;
}


