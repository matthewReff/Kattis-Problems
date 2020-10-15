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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	ll i, j, k;
	ll length;
	bool valid = true;
	string mainString;
	string currString;
	string temp;
	string temp2;
	cin >> mainString;
	length = mainString.size();
	for (i = 1; i < length; i++)
	{
		if (length % i == 0)
		{
			currString = mainString.substr(0, i);
			
			valid = true;
			for (j = 1; j < (length / i); j++)
			{
				temp = "";
				temp += currString.substr(i - 1);
				temp += currString.substr(0, i - 1);
				temp2 = mainString.substr(i*j, i);
				if (temp != temp2)
				{
					valid = false;
				}
				currString = temp;
			}
		}
		if (valid)
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << length << "\n";
	
	
	
	return 0;
}
