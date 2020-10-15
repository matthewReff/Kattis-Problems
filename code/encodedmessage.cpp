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
	int numOfProblems, boardSize, i, j, k;
	string encoded;
	char ** note;
	int x, y;

	cin >> numOfProblems;
	for (k = 0; k < numOfProblems; k++)
	{
		cin >> encoded;
		boardSize = sqrt(encoded.size());
		note = new(nothrow) char *[boardSize];
		for (i = 0; i < boardSize; i++)
		{
			note[i] = new(nothrow) char[boardSize];
		}
		for (i = 0; i < encoded.size(); i++)
		{
			x = i / boardSize;
			y = i % boardSize;
			note[y][boardSize-x-1] = encoded[i];
		}
		for (i = boardSize-1; i >= 0; i--)
		{
			for (j = boardSize-1; j >= 0; j--)
			{
				cout << note[i][j];
			}
			 
		}
		cout << "\n";
	}
	return 0;
}


