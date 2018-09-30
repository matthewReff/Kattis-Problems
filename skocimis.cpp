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
	long long i, j, k;
	int a, b, c;

	cin >> a >> b >> c;

	if ((b - a - 1) > (c - b - 1))
	{
		cout << (b - a - 1);
	}
	else
	{
		cout << (c - b - 1);
	}
	return 0;
}