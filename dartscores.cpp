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
#include <set>

typedef long long ll;
using namespace std;

int main()
{
	ll i, j, k;
	ll cases;
	ll darts;
	ll x, y;
	double temp = 0.0;
	cin >> cases;
	
	for (i = 0; i < cases; i++)
	{
		cin >> darts;
		int total = 0;
		for (j = 0; j < darts; j++)
		{
			cin >> x >> y;
			temp = sqrt(x * x + y * y);
			if (temp <= 20)
			{
				total += 10;
			}
			else if (temp <= 40)
			{
				total += 9;
			}
			else if (temp <= 60)
			{
				total += 8;
			}
			else if (temp <= 80)
			{
				total += 7;
			}
			else if (temp <= 100)
			{
				total += 6;
			}
			else if (temp <= 120)
			{
				total += 5;
			}
			else if (temp <= 140)
			{
				total += 4;
			}
			else if (temp <= 160)
			{
				total += 3;
			}
			else if (temp <= 180)
			{
				total += 2;
			}
			else if (temp <= 200)
			{
				total += 1;
			}
		}
		cout << total << "\n";
	}
	return 0;
}
