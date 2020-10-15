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
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull i, j, k;
	ll keyLen;
	string line;

	while (cin >> keyLen && keyLen != 0)
	{
		string outLine = "'";
		string lineChunk;
		vector<ll> permuteKey(keyLen);
		for (i = 0; i < keyLen; i++)
		{
			cin >> permuteKey[i];
		}
		cin.ignore();
		getline(cin, line);
		if (line.size() % keyLen != 0)
		{
			for (j = 0; j < (line.size() % keyLen); j++)
			{
				line += ' ';
			}
		}

		for (j = 0; j < line.size() / keyLen; j++)
		{
			lineChunk = line.substr(j * keyLen, keyLen);
			string encryptChunk;
			encryptChunk.resize(keyLen);
			for (k = 0; k < keyLen; k++)
			{
				encryptChunk[k] = lineChunk[permuteKey[k] - 1];
			}
			outLine += encryptChunk;
		}
		outLine += "'";
		cout << outLine << "\n";

	}
	
	return 0;
}
