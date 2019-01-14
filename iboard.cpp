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

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull i, j, k;
	string line;
	int temp;
	bool leftState, rightState;
	while (getline(cin, line))
	{
		leftState = true;
		rightState = true;
		for (auto letter : line)
		{
			for (i = 0; i < 7; i++)
			{
				if ((letter >> i) & 1)
				{

					leftState = !leftState;
				}
				else
				{
					rightState = !rightState;
				}
			}		
		}
		if (leftState && rightState)
		{
			cout << "free\n";
		}
		else
		{
			cout << "trapped\n";
		}
	}
	return 0;
}
