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
	int * sizes;
	string * colors;
	string tempString;

	string first;
	int firstInt;
	string second;
	int secondInt;
	bool sorted = false;

	cin >> cases;
	sizes = new(nothrow) int[cases];
	colors = new(nothrow) string[cases];

	for (i = 0; i < cases; i++)
	{
		cin >> first >> second; 
		try
		{
			firstInt = stoi(first);
			sizes[i] = firstInt;
			colors[i] = second;
		}
		catch (invalid_argument)
			{
				sizes[i] = stoi(second) * 2;
				colors[i] = first;
			}
		
	}

	while (!sorted)
	{
		sorted = true;
		for (i = 0; i < cases-1; i++)
		{
			if (sizes[i] > sizes[i + 1])
			{
				temp = sizes[i];
				sizes[i] = sizes[i + 1];
				sizes[i + 1] = temp;
				tempString = colors[i];
				colors[i] = colors[i + 1];
				colors[i + 1] = tempString;
				sorted = false;
			}
		}
	}

	for (j = 0; j < cases; j++)
	{
		cout << colors[j] << "\n";
	}
	return 0;
}