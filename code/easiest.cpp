#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;

int main()
{
	int cases, i, j, k, origSum, testCase, sum;
	string testString;
	cin >> cases;
	while (cases != 0)
	{

		origSum = 0;
		testString = to_string(cases);
		for (i = 0; i < testString.size(); i++)
		{
			origSum += testString[i] - '0';
		}

		sum = 0;
		i = 10;
		while (sum != origSum)
		{
			i++;
			sum = 0;
			testCase = cases*i;
			testString = to_string(testCase);
			for (j = 0; j < testString.size(); j++)
			{
				sum += testString[j] - '0';
			}
		}
		cout << i << "\n";
		cin >> cases;
	}

	return 0;
}


