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


int main()
{
	ll i, j, k;
	
	ll tempNum;
	ll numbers;
	string tempString;
	bool valid = true;
	
	cin >> numbers;
	for (i = 1; i < numbers + 1; i++)
	{
		cin >> tempString;
		if (tempString != "mumble")
		{
			tempNum = stoi(tempString);
			if (tempNum != i)
			{
				valid = false;
			}
		}
	}
	if (valid)
	{
		cout << "makes sense\n";
	}
	else
	{
		cout << "something is fishy\n";
	}
	return 0;
}



