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
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main()
{
	int i, j, k;
	int cases;
	int x, shiftx;
	int shiftTemp, temp;
	
	cin >> cases;
	vector<int> decodes(cases);
	for (i = 0; i < cases; i++)
	{
		cin >> decodes[i];
	}

	for (i = 0; i < cases; i++)
	{
		vector<int> xBits(8, 0);
		vector<int> shiftBits(8, 0);
		

		for (j = 7; j >= 0; j--)
		{
			//cout << (decodes[i] >> (7 - j)) << " ";
			//cout << shiftBits[j] << "\n";
			xBits[j] = ((decodes[i] >> (7 - j))& 1) ^ shiftBits[j];
			if (j != 0)
				shiftBits[j - 1] = xBits[j];
		}
		string outString;
		for (j = 0; j < 8; j++)
		{
			outString += xBits[j] + '0';
		}
		cout << stoi(outString, NULL, 2) << " ";
	}
	return 0;
}
