#define _USE_MATH_DEFINES
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

void floodFill(ll i, ll j, vector<string> &image, vector<vector<bool>> &found, vector<vector<ll>> &groupNums,
	ll height, ll width, char fillChar, ll fillNum)
{
	found[i][j] = true;
	groupNums[i][j] = fillNum;
	ll tempi, tempj;
	for (ll k = 0; k < 4; k++)
	{
		switch (k) {
		case 0:
			tempi = i - 1;
			tempj = j;
			break;
			break;
		case 1:
			tempi = i;
			tempj = j + 1;
			break;
		case 2:
			tempi = i + 1;
			tempj = j;
			break;
			break;
		case 3:
			tempi = i;
			tempj = j - 1;
			break;

		};


		if (tempi >= 0 && tempi < height && tempj >= 0 &&
			tempj < width && !found[tempi][tempj] &&
			image[tempi][tempj] == fillChar)
		{
			floodFill(tempi, tempj, image, found, groupNums, height,  width, fillChar, fillNum);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll i, j, k;

	ll rows, cols;
	ll numQueries;
	ll groupAssignNum = 0;
	ll r1, r2, c1, c2;
	cin >> rows >> cols;
	vector<vector<ll>> groupNums(rows);
	vector<string> image(rows);
	vector<vector<bool>> found(rows);
	for (i = 0; i < rows; i++)
	{
		cin >> image[i];
		groupNums[i].resize(cols);
		found[i].resize(cols, false);
	}
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (!found[i][j])
			{
				floodFill(i, j, image, found, groupNums, rows, cols, image[i][j], groupAssignNum);
				groupAssignNum++;
			}
		}
	}
					//floodFill(i, j, image, found, height, width);
		
	/*
	for (auto line : groupNums)
	{
		for (auto segment : line)
		{
			cout << segment << " ";
		}
		cout << "\n";
	}
	*/

	cin >> numQueries;
	for (i = 0; i < numQueries; i++)
	{
		cin >> r1 >> c1 >> r2 >> c2;

		//convert to zero indexed
		r1--;
		r2--;
		c1--;
		c2--;
		if (groupNums[r1][c1] == groupNums[r2][c2])
		{
			if (image[r1][c1] == '0')
			{
				cout << "binary\n";
			}
			else
			{
				cout << "decimal\n";
			}
		}
		else
		{
			cout << "neither\n";
		}
	}
	return 0;
}