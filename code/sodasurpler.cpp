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
	int e, f, c;
	int total, drank;
	drank = 0;
	cin >> e >> f >> c;

	total = e + f;

	while (total >= c)
	{
		total -= c;
		drank++;
		total++;
	}
	cout << drank << "\n";
	return 0;
}