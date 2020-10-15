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
	long long i, j ,k;
	long long cases;
	long long index;
	long long snaps;
	string convert;
	string snapString = "";
	bool powered = true;

	cin >> cases;

	j = 0;

	for (i = 0; i < cases; i++)
	{
		powered = true;
		snapString.clear();
		cin >> index >> snaps;
		while (pow(2, j+1) <= snaps)
		{
			j++;
		}
		while (snaps > 0)
		{
			if (pow(2, j) > snaps)
			{
				snapString.append("0");
			}
			else
			{
				snapString.append("1");
				snaps -= pow(2, j);
			}
			j--;
		}

		while (j >= 0)
		{
			snapString.append("0");
			j--;
		}

		reverse(snapString.begin(), snapString.end());

		for (k = 0; k < 100; k++)
		{
			snapString.append("0");
		}

		for (k = index; k > 0; k--)
		{
			if (snapString[k-1] == '0')
			{
				powered = false;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		if (snapString[index - 1] == '1' && powered)
		{
			cout << "ON\n";
		}
		else
		{
			cout << "OFF\n";
		}
		
	}
	return 0;
}