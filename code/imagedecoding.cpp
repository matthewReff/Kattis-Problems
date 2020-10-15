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

vector<string> pySplit(string & splitString, char seperator = ' ')
{
	int endIndex = 0;
	vector<string > seperated;
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
	return seperated;
}

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll scanLines;
    string thisLine;
    vector<string> result;
    bool firstImage = true;
    while(cin >> scanLines && scanLines != 0)
    {
    	cin.ignore();
    	ll lineLength = -1;
    	bool valid = true;
    	if(!firstImage)
    	{
    		cout << "\n";
    	}
    	else
    	{
    		firstImage = false;
    	}
    	for(k = 0; k < scanLines; k++)
    	{
	    	getline(cin, thisLine);
	    	result = pySplit(thisLine);
	    	char thisChar = result[0][0];
	    	ll amount;
	    	ll currentLength = 0;
	    	for(i = 1; i < (ll)result.size(); i++)
	    	{
	    		amount = stoi(result[i]);
	    		currentLength += amount;
	    		for(j = 0; j < amount; j++)
	    		{
	    			cout << thisChar;
	    		}
	    		if(thisChar == '#')
	    		{
	    			thisChar = '.';
	    		}
	    		else
	    		{
	    			thisChar = '#';
	    		}
	    	}
	    	if(lineLength == -1)
	    	{
	    		lineLength = currentLength;
	    	}
	    	if(currentLength != lineLength)
	    	{
	    		valid = false;
	    	}
	    	cout << "\n";
    	}
    	if(!valid)
    	{
    		cout << "Error decoding image\n";
    	}
    }
    return 0;
}
