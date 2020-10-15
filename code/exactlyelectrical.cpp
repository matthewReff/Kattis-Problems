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
	int startX, startY, endX, endY, power;
	int distance;

	cin >> startX >> startY >> endX >> endY >> power;

	distance = abs(startX - endX) + abs(startY - endY);

	if ((power - distance) % 2 == 0 && (power - distance) >= 0 )
	{
		cout << "Y";
	}
	else
	{
		cout << "N";
	}
	return 0;
}