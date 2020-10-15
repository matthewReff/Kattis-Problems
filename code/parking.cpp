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
	int high, low;
	int parkA[101];
	int parkB[101];
	int parkC[101];
	int prices[4] = {0,0,0,0};
	int cost = 0;
	for (i = 1; i < 4; i++)
	{
		cin >> prices[i];
	}

	for (i = 0; i < 101; i++)
	{
		parkA[i] = 0;
		parkB[i] = 0;
		parkC[i] = 0;
	}

	cin >> low >> high;

	for (i = low; i < high; i++)
	{
		parkA[i] = 1;
	}

	cin >> low >> high;

	for (i = low; i < high; i++)
	{
		parkB[i] = 1;
	}

	cin >> low >> high;

	for (i = low; i < high; i++)
	{
		parkC[i] = 1;
	}

	for (i = 1; i < 101; i++)
	{
		cost += prices[parkA[i] + parkB[i] + parkC[i]] * (parkA[i] + parkB[i] + parkC[i]);
	}

	cout << cost << "\n";
	return 0;
}