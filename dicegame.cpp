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
	int l1, h1, l2, h2, l3, h3, l4, h4;
	double avg1, avg2, avg3, avg4;
	int sum;
	cin >> l1 >> h1 >> l2 >> h2 >> l3 >> h3 >> l4 >> h4;

	sum = 0;
	for (i = l1; i <= h1; i++)
	{
		sum += i;
	}
	avg1 = sum / double(h1 - l1 + 1);

	sum = 0;
	for (i = l2; i <= h2; i++)
	{
		sum += i;
	}
	avg2 = sum / double(h2 - l2 + 1);

	sum = 0;
	for (i = l3; i <= h3; i++)
	{
		sum += i;
	}
	avg3 = sum / double(h3 - l3 + 1);

	sum = 0;
	for (i = l4; i <= h4; i++)
	{
		sum += i;
	}
	avg4 = sum / double(h4 - l4 + 1);

	if ((avg1 + avg2) > (avg3 + avg4))
	{
		cout << "Gunnar";
	}
	else if ((avg1 + avg2) < (avg3 + avg4))
	{
		cout << "Emma";
	}
	else
	{
		cout << "Tie";
	}
	return 0;
}