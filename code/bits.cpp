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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	ull i, j, k;
	ull cases;
	string temp;
	ull temp2;
	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		ull maxes = 0;
		cin >> temp;
		for (j = 1; j <= temp.size(); j++)
		{
			ull currMax= 0;
			temp2 = stoi(temp.substr(0, j));
			for (k = 0; k < 31; k++)
			{
				if (temp2 >> k & 1)
				{
					currMax++;
				}
			}
			if (currMax > maxes)
			{
				maxes = currMax;
			}
		}
		cout << maxes << "\n";
	}
	return 0;
}
