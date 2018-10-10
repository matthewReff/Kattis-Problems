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
#include <numeric>
#include <set>

typedef long long ll;
using namespace std;

void fillAmoeba(vector<string>  & dish, vector<vector<bool>> & visited,
	ll x, ll y, ll & rows, ll & cols);
int main()
{
	ll i, j, k;
	
	ll rows, cols;
	ll num = 0;
	cin >> rows >> cols;

	vector<string> dish(rows);
	vector<vector<bool>> visited (rows);
	for (i = 0; i < rows; i++)
	{
		cin >> dish[i];
		for (j = 0; j < cols; j++)
		{
			visited[i].push_back(false);
		}
	}
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (dish[i][j] == '#' && !visited[i][j])
			{
				fillAmoeba(dish, visited, i, j, rows, cols);
				num++;
			}
		}
	}
	cout << num << "\n";
	return 0;
}

void fillAmoeba(vector<string>  & dish, vector<vector<bool>> & visited,
	ll x, ll y, ll & rows, ll & cols)
{
	bool found = false;
	visited[x][y] = true;
	ll tempX, tempY;
	while (!found)
	{
		found = true;
		for (int i = 0; i < 8; i++)
		{
			switch (i)
			{
			case 0:
				tempX = x;
				tempY = y + 1;
				break;
			case 1:
				tempX = x + 1;
				tempY = y + 1;
				break;
			case 2:
				tempX = x + 1;
				tempY = y;
				break;
			case 3:
				tempX = x + 1;
				tempY = y - 1;
				break;
			case 4:
				tempX = x;
				tempY = y - 1;
				break;
			case 5:
				tempX = x - 1;
				tempY = y - 1;
				break;
			case 6:
				tempX = x - 1;
				tempY = y;
				break;
			case 7:
				tempX = x - 1;
				tempY = y + 1;
				break;
			};
			if (tempX >= 0 && tempX < rows && tempY >= 0 &&
				tempY < cols && dish[tempX][tempY] == '#' && !visited[tempX][tempY])
			{
				x = tempX;
				y = tempY;
				visited[x][y] = true;
				found = false;
			}
		}
	}
}


