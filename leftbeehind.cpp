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

	int sour, normal;

	cin >> normal >> sour;

	while (sour != 0 || normal != 0)
	{
		if (sour + normal == 13)
		{
			cout << "Never speak again.\n";
		}
		else if (sour > normal)
		{
			cout << "Left beehind.\n";
		}
		else if (normal > sour)
		{
			cout << "To the convention.\n";
		}
		else
		{
			cout << "Undecided.\n";
		}
		cin >> normal >> sour;
	}
	return 0;
}