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
	ll i, j, k;
	ll nums[5];
	ll temp;
	bool sorted = false;
	for (i = 0; i < 5; i++)
	{
		cin >> nums[i];
	}

	while (!sorted)
	{
		sorted = true;
		for (i = 0; i < 4; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				sorted = false;
				swap(nums[i], nums[i+1]);
				for (j = 0; j < 5; j++)
				{
					cout << nums[j] << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}
