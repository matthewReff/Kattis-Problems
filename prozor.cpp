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
	long long i, j, k, l;
	int r, s, e;
	int mostSoFar = 0;
	int mX, mY;
	int tempFlys;
	vector<string> window;
	string windowLine;

	cin >> r >> s >> e;
	for (i = 0; i < r; i++)
	{
		cin >> windowLine;
		window.push_back(windowLine);
	}
	for (i = 0; i < r - e + 1; i++) //rows
	{
		for (j = 0; j < s - e + 1; j++) //cols
		{
			tempFlys = 0;
			for (k = 1; k < e - 1; k++) //rows in subwindow
			{
				for (l = 1; l < e - 1; l++) //cols in subwindow
				{
					if (window[i + k][j + l] == '*')
					{
						tempFlys++;
					}
				}
				if (tempFlys > mostSoFar)
				{
					mostSoFar = tempFlys;
					mX = i;
					mY = j;
				}
			}
		}
	}
	window[mX][mY] = '+';
	window[mX + e - 1][mY] = '+';
	window[mX + e - 1][mY + e - 1] = '+';
	window[mX][mY + e - 1] = '+';

	for (i = mX + 1; i < mX + e - 1; i++)
	{
		window[i][mY] = '|';
	}

	for (i = mX + 1; i < mX + e - 1; i++)
	{
		window[i][mY + e - 1] = '|';
	}

	for (i = mY + 1; i < mY + e - 1; i++)
	{
		window[mX][i] = '-';
	}

	for (i = mY + 1; i < mY + e - 1; i++)
	{
		window[mX + e - 1][i] = '-';
	}

	cout << mostSoFar << "\n";
	for (auto i : window)
	{
		cout << i << "\n";
	}
	
	return 0;
}