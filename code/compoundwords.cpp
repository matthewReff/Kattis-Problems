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
	set<string> uniques;
	string temp;
	string thing;
	vector<string> words;

	while (cin >> temp)
	{
		words.push_back(temp);
	}
	//words = { "a", "bb", "ab", "b" };
	for (i = 0; i < words.size(); i++)
	{
		for (j = 0; j < words.size(); j++)
		{
			if (j != i)
			{
				thing = words[j] + words[i];
				uniques.insert(thing);
			}
		}
	}

	set<string>::iterator itr = uniques.begin();

	while (itr != uniques.end())
	{
		cout << *itr << "\n";
		itr++;
	}

	return 0;
}
