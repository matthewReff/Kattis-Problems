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
	
	int m, n, s;
	double totalN = 0.0;
	double totalS = 0.0;
	double minuteTime;

	cin >> m;

	for (i = 0; i < m; i++)
	{
		cin >> n >> s;
		totalN += n;
		totalS += s;
	}

	cout << fixed << setprecision(10);
	minuteTime = totalS / (totalN * 60);
	if (minuteTime <= 1.0)
	{
		cout << "measurement error";
	}
	else
	{
		cout << minuteTime;
	}
	return 0;
}