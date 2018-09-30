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
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k;
	
	ll width, length;
	ll instructions;
	ll actX, actY;
	ll thinkX, thinkY;
	char direction;
	ll distance;

	cin >> width >> length;

	while (width != 0 && length != 0)
	{
		actX = 0;
		actY = 0;
		thinkX = 0;
		thinkY = 0;

		cin >> instructions;

		for (i = 0; i < instructions; i++)
		{
			cin >> direction >> distance;

			if (direction == 'u' || direction == 'd')
			{
				if (direction == 'd')
				{
					distance *= -1;
				}
				if (actY + distance >= length - 1)
				{
					actY = length - 1;
					thinkY += distance;
				}
				else if (actY + distance < 0)
				{
					actY = 0;
					thinkY += distance;
				}
				else
				{
					actY += distance;
					thinkY += distance;
				}
			}
			else
			{
				if (direction == 'l')
				{
					distance *= -1;
				}
				if ((actX + distance) >= (width - 1))
				{
					actX = width - 1;
					thinkX += distance;
				}
				else if (actX + distance < 0)
				{
					actX = 0;
					thinkX += distance;
				}
				else
				{
					actX += distance;
					thinkX += distance;
				}
			}
		}

		cout << "Robot thinks " << thinkX << " " << thinkY << "\n";
		cout << "Actually at " << actX << " " << actY << "\n";
		cin >> width >> length;
	}
	
	return 0;
}