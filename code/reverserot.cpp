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
	int cases, i, j, k, temp;
	int turns;
	string newString;
	string decode = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	string cypered;

	cin >> turns;
	while (turns != 0)
	{
		cypered.clear();
		cin >> newString;
		for (i = 0; i < newString.size(); i++)
		{
			for (j = 0; j < 28; j++)
			{
				if (newString[i] == decode[j])
				{
					cypered.insert(cypered.end(), decode[(j + turns)%28]);
				}
			}
		}
		reverse(cypered.begin(), cypered.end());
		cout << cypered << "\n";
		cin >> turns;
	}
	return 0;
}