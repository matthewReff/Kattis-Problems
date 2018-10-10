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

int recurse(string & fullString, string & welcome, ll fullIndex, ll welcomeIndex, ll total);
int main()
{
	ll i, j, k;
	
	ll cases;
	ll temp;

	string fullString;

	string welcome = "welcome to code jam";
	cin >> cases;
	cin.ignore();
	for (i = 0; i < cases; i++)
	{
		string outString;
		string tempString;
		getline(cin, fullString);
		temp = recurse(fullString, welcome, 0, 0, 0);
		tempString = to_string(temp);
		for (j = 0; j < 4 - tempString.size(); j++)
		{
			outString += "0";
		}
		outString += tempString;
		cout << "Case #" << i + 1 << ": " << outString << "\n";
	}
	return 0;
}

int recurse(string & fullString, string & welcome, ll fullIndex, ll welcomeIndex, ll total)
{
	if (welcomeIndex == welcome.size())
	{
		return total + 1;
	}
	else if (fullIndex == fullString.size())
	{
		return total;
	}
	for (int i = fullIndex; i < fullString.size(); i++)
	{
		if (welcome[welcomeIndex] == fullString[i])
		{
			total =  recurse(fullString, welcome, i, welcomeIndex + 1, total);
		}
	}
	return total;
}


