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
	int cases, dataSet, n;

	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		cout << fixed;
		cin >> dataSet >> n;
		cout << dataSet << " " << ((n * (n + 1)) / 2) << " " << 
			int(pow(n,2)) << " " << (n * (n+1)) << "\n";
	}
	return 0;
}