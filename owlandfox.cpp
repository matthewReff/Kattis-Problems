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
	ll i, j, k, l;
	
	ll cases;
	ll testNum;
	ll testSum;
	ll currNum;
	ll currSum;
	bool solved = false;

	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		testSum = 0;
		solved = false;
		cin >> testNum;
		currNum = testNum - 1;
		for (auto digit : to_string(testNum))
		{
			testSum += digit - '0';
		}
		while (!solved && currNum > 0)
		{
			currSum = 0;
			for (auto digit : to_string(currNum))
			{
				currSum += digit - '0';
			}
			if (testSum - 1 == currSum)
			{
				solved = true;
			}
			else
			{
				currNum--;
			}
		}
		cout << currNum << "\n";
	}
	return 0;
}