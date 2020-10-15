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
	int absDiff, totMen, totWomen;
	string clubLine;		
	bool possible = true;

	cin >> absDiff;
	cin >> clubLine;

	totMen = 0;
	totWomen = 0;
	while (clubLine.size() > 0 && possible)
	{
		possible = false;
		if (clubLine.size() == 1)
		{
			if (abs((totMen + 1) - totWomen) <= absDiff && (clubLine[0] == 'M'))
			{
				totMen++;
				possible = true;
				clubLine.erase(clubLine.begin());
			}
			else if (abs((totWomen + 1) - totMen) <= absDiff && (clubLine[0] == 'W'))
			{
				totWomen++;
				possible = true;
				clubLine.erase(clubLine.begin());
			}
		}
		else
		{
			if (abs((totMen + 1) - totWomen) <= absDiff && (clubLine[0] == 'M' || clubLine[1] == 'M'))
			{
				totMen++;
				possible = true;
				if (clubLine[0] == 'M')
				{
					clubLine.erase(clubLine.begin());
				}
				else
				{
					clubLine.erase(clubLine.begin()+1);
				}
			}
			else if (abs((totWomen + 1) - totMen) <= absDiff && (clubLine[0] == 'W' || clubLine[1] == 'W'))
			{
				totWomen++;
				possible = true;
				if (clubLine[0] == 'W')
				{
					clubLine.erase(clubLine.begin());
				}
				else
				{
					clubLine.erase(clubLine.begin() + 1);
				}
			}
		}

	}
	cout << totMen + totWomen;
	return 0;
}