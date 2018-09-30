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

	ll longWords;
	ll shortWords;
	ll shortIndex;
	bool found = false;

	cin >> longWords >> shortWords;

	vector<string> longW ( longWords );
	vector<string>::iterator vecStrItr;
	vector<string>::iterator bodgeItr;
	string shortWord;

	for (i = 0; i < longWords; i++)
	{
		cin >> longW[i];
	}

	for (i = 0; i < shortWords; i++)
	{
		cin >> shortWord;
		shortWord[0] = tolower(shortWord[0]);
		shortWord[1] = tolower(shortWord[1]);
		shortWord[2] = tolower(shortWord[2]);
		found = false;


		for (vecStrItr = longW.begin(); !found && vecStrItr != longW.end(); vecStrItr++) //iterate through words
		{
			shortIndex = 0;

			for (k = 0; !found && k < (*vecStrItr).size(); k++) //iterate along the long word
			{
				if ((*vecStrItr)[k] == shortWord[shortIndex])
				{
					shortIndex++;
					if (shortIndex == 3)
					{
						bodgeItr = vecStrItr;
						found = true;
					}
				}
			}
		}
		if (found)
		{
			cout << *bodgeItr << "\n";
		}
		else
		{
			cout << "No valid word\n";
		}
	}
	return 0;
}