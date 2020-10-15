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

	long long i, j, k;

	int cases;
	int charNum;
	bool charUsed[26];
	bool isPangram = true;
	string pangramString;

	cin >> cases;
	cin.ignore();

	for (i = 0; i < cases; i++)
	{
		isPangram = true;
		for (j = 0; j < 26; j++)
		{
			charUsed[j] = false;
		}

		getline(cin, pangramString);

		for (j = 0; j < pangramString.size(); j++)
		{
			charNum = tolower(pangramString[j]) - 'a';
			if (charNum < 26 && charNum >= 0)
			{
				charUsed[charNum] = true;
			}
		}
		for (j = 0; j < 26; j++)
		{
			if (!charUsed[j])
			{
				isPangram = false;
			}
		}
		if (isPangram)
		{
			cout << "pangram\n";
		}
		else
		{
			cout << "missing ";
			for (j = 0; j < 26; j++)
			{
				if (!charUsed[j])
				{
					cout << char(j + 'a');
				}
			}
			cout << "\n";

		}
	}
	return 0;
}