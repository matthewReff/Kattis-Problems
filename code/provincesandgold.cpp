#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	
	ll a, b, c;
	ll total = 0;
	string prop, ore;
	bool both;
	cin >> a >> b >> c;
	total = a * 3 + b * 2 + c * 1;
	if (total >= 6)
	{
		ore = "Gold";
	}
	else if (total >= 3)
	{
		ore = "Silver";
	}
	else
	{
		ore = "Copper";
	}

	if (total >= 8)
	{
		prop = "Province";
	}
	else if (total >= 5)
	{
		prop = "Duchy";
	}
	else if (total >= 2)
	{
		prop = "Estate";
	}
	if (total < 2)
	{
		cout << ore << "\n";
	}
	else
	{
		cout << prop << " or " << ore << "\n";
	}
	return 0;
}
