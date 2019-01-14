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
	int matching = 0;
	int mismatching = 0;
	int correct;
	int len, temp, remaining;
	string str1, str2;

	cin >> correct >> str1 >> str2;
	len = str1.size();
	for (i = 0; i < len; i++)
	{
		if (str1[i] == str2[i])
		{
			matching++;
		}
		else
		{
			mismatching++;
		}
	}
	remaining = correct;
	temp = min(correct, matching);
	remaining -= temp;

	temp += (mismatching - remaining);
	cout << temp << "\n";
	return 0;
}
