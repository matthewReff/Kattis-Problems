#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll words;
	cin >> words;
	cin.ignore();
	set<string> uniques;

	string temp;
	for(i = 0; i < words; i++)
	{
		string newWord;
		getline(cin, temp);
		for(j = 0; j < temp.size(); j++)
		{
			char thisLetter = temp[j];
			thisLetter = tolower(thisLetter);
			if(thisLetter == '-')
			{
				thisLetter = ' ';
			}
			newWord += thisLetter;
		}
		uniques.insert(newWord);
	}    

	cout << uniques.size() << "\n";
    return 0;
}
