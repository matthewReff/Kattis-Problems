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

typedef long long ll;
using namespace std;

ll gcd( ll a, ll b);
ll lcm(ll a, ll b);
int main()
{
	ll i, j, k;
	
	ll tempNum;
	ll charBuffer = 1;
	string codeString;
	char tempChar;
	char prevChar;
	char codeChar;
	cin >> codeChar;

	if (codeChar == 'D')
	{
		while (cin >> tempChar >> tempNum)
		{
			for (i = 0; i < tempNum; i++)
			{
				cout << tempChar;
			}
		}
		cout << "\n";
	}
	else
	{
		cin >> codeString;
		codeString += "\n";
		prevChar = codeString[0];
		for (i = 1; i < codeString.size(); i++)
		{
			if (codeString[i] != prevChar)
			{
				cout << prevChar << charBuffer;
				prevChar = codeString[i];
				charBuffer = 1;
			}
			else
			{
				charBuffer++;
			}
		}
		cout << "\n";
	}
	return 0;
}



