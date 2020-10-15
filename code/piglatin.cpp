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

void pySplit(string & splitString, char seperator, vector<string> & seperated)
{
	int endIndex = 0;
	seperated.clear();
	seperated.push_back("");
	for (unsigned int i = 0; i < splitString.size(); i++)
	{
		if (splitString[i] == seperator)
		{
			endIndex++;
			seperated.push_back("");
		}
		else
		{
			seperated[endIndex] += splitString[i];
		}
	}
}



int main()
{
	ull i, j, k;
	string thing;
	string temp;
	vector<string> splitLine;
	while (getline(cin, thing))
	{
		pySplit(thing, ' ', splitLine);
		for (auto i : splitLine)
		{
			temp = "";
			bool found = false;
			if (i[0] == 'a' || i[0] == 'e' || i[0] == 'i'
				|| i[0] == 'o' || i[0] == 'u' || i[0] == 'y')
			{
				temp = i + "yay";
			}
			else
			{
				j = 0;
				while (j < i.size() && !found)
				{
					if (i[j] == 'a' || i[j] == 'e' || i[j] == 'i'
						|| i[j] == 'o' || i[j] == 'u' || i[j] == 'y')
					{
						found = true;
					}
					j++;
				}
				j -= 1;
				temp += i.substr(j);
				temp += i.substr(0, j);
				temp += "ay";
			}
			cout << temp << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
