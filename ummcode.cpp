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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    string speech;
    string generatedString = "";
    string message = "";
    while(cin >> speech)	
    {
    	string converted = "";
    	bool valid = true;
		for(i = 0; i < speech.size() && valid; i++)
		{
			if((speech[i] != 'u' && speech[i] != 'm' && !ispunct(speech[i])))
			{
				valid = false;
			}
			else
			{
				if(speech[i] == 'u')
				{
					converted += '1';
				}
				else if(speech[i] == 'm')
				{
					converted += '0';
				}
			}
		}
		if(valid)
		{
			generatedString += converted;
		}    	
    }

    //cout << generatedString << "\n";
    for(i = 0; i < generatedString.size(); i+=7)
    {
    	string temp = generatedString.substr(i, 7);
    	//cout << temp << "\n";
    	//cout << stoi(temp, nullptr, 2) << "\n";
    	char actualChar = char(stoi(temp, nullptr, 2));
    	message += actualChar;
    }

    cout << message << "\n";
    return 0;
}
