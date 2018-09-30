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

	ll rooms;
	ll booked;
	ll bookedRoom;
	bool * hotel;

	cin >> rooms >> booked;

	if (rooms == booked)
	{
		cout << "too late\n";
	}
	else
	{
		hotel = new (nothrow) bool[rooms];
		for (i = 0; i < rooms; i++)
		{
			hotel[i] = false;
		}
		for (i = 0; i < booked; i++)
		{
			cin >> bookedRoom;
			hotel[bookedRoom - 1] = true;
		}
		i = 0;
		while (i < rooms && hotel[i])
		{
			i++;
		}
		cout << i + 1;
	}
	return 0;
}