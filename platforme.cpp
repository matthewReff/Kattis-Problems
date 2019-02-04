#define _USE_MATH_DEFINES
#include <fstream>
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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;


struct platform
{
	int y, left, right;
	bool operator< (platform right)
	{
		if (y == right.y)
		{
			return left < right.left;
		}
		return y < right.y;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll i, j, k;

	ll numPlatforms;
	ll totalLength = 0;
	bool foundLeft, foundRight;
	ll y, x1, x2;
	cin >> numPlatforms;
	vector<platform> platforms(numPlatforms);
	for (i = 0; i < numPlatforms; i++)
	{
		cin >> platforms[i].y >> platforms[i].left >> platforms[i].right;
	}

	sort(platforms.rbegin(), platforms.rend());

	for (i = 0; i < numPlatforms; i++)
	{
		foundLeft = false;
		foundRight = false;
		for (j = i + 1; j < numPlatforms && (!foundLeft || !foundRight); j++)
		{
			if (!foundLeft && platforms[i].left >= platforms[j].left && platforms[i].left < platforms[j].right)
			{
				totalLength += platforms[i].y - platforms[j].y;
				foundLeft = true;
			}
			if (!foundRight && platforms[i].right > platforms[j].left && platforms[i].right <= platforms[j].right)
			{
				totalLength += platforms[i].y - platforms[j].y;
				foundRight = true;
			}
		}
		if (!foundLeft)
		{
			totalLength += platforms[i].y;
		}
		if (!foundRight)
		{
			totalLength += platforms[i].y;
		}
	}

	cout << totalLength << "\n";
	return 0;
}