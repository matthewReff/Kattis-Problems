#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k;

	string key;
	ll lowX, highX, lowY, highY;
	lowX = 0;
	lowY = 0;
	cin >> key;
	highY = pow(2, key.size()) - 1;
	highX = pow(2, key.size()) - 1;
	

	for (auto subKey : key)
	{
		if (subKey == '0')
		{
			highY -= ((highY - lowY + 1) / 2);
			highX -= ((highX - lowX + 1) / 2);
		}
		else if (subKey == '1')
		{
			highY -= ((highY - lowY + 1) / 2);
			lowX += ((highX - lowX + 1) / 2);
		}
		else if (subKey == '2')
		{
			lowY += ((highY - lowY + 1) / 2);
			highX -= ((highX - lowX + 1) / 2);
		}
		else
		{
			lowY += ((highY - lowY + 1) / 2);
			lowX += ((highX - lowX + 1) / 2);
		}

	}
	cout << key.size() << " " << lowX << " " << lowY << "\n";
	return 0;
}