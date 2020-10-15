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
	int cases, i, j, k;

	cin >> cases;

	cout << cases << ":\n";

	for (i = 2; i < cases; i++)
	{
		if ((cases / (2 * i - 1) * (2 * i - 1)) + i == cases)
		{
			cout << i << "," << i - 1 << "\n";
		}

		if (cases % (i * 2 - 1) == 0)
		{
			cout << i << "," << i - 1 << "\n";
		}

		if (cases % i == 0)
		{
			cout << i << "," << i << "\n";
		}
		else if (cases % (i * 2) == 0)
		{
			cout << i << "," << i << "\n";
		}

		
	}
	return 0;
}


