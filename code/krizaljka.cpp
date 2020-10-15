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
	
	string a, b;
	ll matchI, matchJ;
	bool matched = false;
	cin >> a >> b;
	vector<string> board;

	for (i = 0; !matched && i < a.size(); i++)
	{
		for (j = 0; !matched && j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				matched = true;
				matchI = i;
				matchJ = j;
			}
		}
	}

	for (i = 0; i < b.size(); i++)
	{
		string temp = "";
		for(j = 0; j < a.size(); j++)
		{
			temp += '.';
		}
		board.push_back(temp);
	}

	board[matchJ] = a;

	for (i = 0; i < b.size(); i++)
	{
		board[i][matchI] = b[i];
	}
	for (i = 0; i < board.size(); i++)
	{
		cout << board[i] << "\n";
	}
	return 0;
}
