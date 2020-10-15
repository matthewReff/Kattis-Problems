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
#include <stack>

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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

	string arrow = "->";
	map<string, bool> used;
    ll lines;
    cin >> lines;
    cin.ignore();

    for(int i = 0; i < lines; i++)
    {
    	string thisLine;
    	getline(cin, thisLine);
    	size_t pos = thisLine.find(arrow);

    	string lefts = thisLine.substr(0, pos);
    	vector<string> leftVals = pySplit(lefts);
    	ll rightLoc = pos + arrow.size() + 1;
    	string rights = thisLine.substr(rightLoc, thisLine.size() - rightLoc);
    	vector<string> rightVals = pySplit(rights);
    	
    	for(int j = 0; j < (int)leftVals.size(); j++)
    	{
    		if(leftVals[j] != "" && !used[leftVals[j]])
    		{
    			cout << i + 1 << "\n";
    			return 0;
    		}
    	}

    	for(int j = 0; j < (int)rightVals.size(); j++)
    	{
    		used[rightVals[j]] = true;
    	}
    	
    }
    cout << "correct\n";
    return 0;
}
