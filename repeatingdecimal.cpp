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

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k;

	ll numerator, denominator, decimals, temp;
	string outString = "";
	while(cin >> numerator)
	{
		cin >> denominator >> decimals;
		outString = "0.";
		for (i = 0; i < decimals; i++)
		{
			numerator *= 10;
			temp = numerator / denominator;
			outString += to_string(temp);
			numerator -= (temp * denominator);
		}
		cout << outString << "\n";
	}
	return 0;
}