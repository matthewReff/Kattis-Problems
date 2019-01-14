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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll rules, iterations;
    string line;
    string tempString;
    vector<string> split;
    map<char, string> decode;
    cin >> rules >> iterations;
    cin.ignore();
    for(i = 0; i < rules; i++)
    {
        getline(cin, line);
        split = pySplit(line);
        if(split[2] != "")
        {
            decode[split[0][0]] = split[2];        
        } 
    }
    getline(cin, line);
    
    for(i = 0; i < iterations; i++)
    {
        tempString = "";
        for(auto element : line)
        {
            if (decode.find(element) != decode.end())
            {
                tempString += decode[element];
            }
            else
            {
                tempString += element;
            }
        }
        line = tempString;
    }
    cout << line << "\n";
    
    /*
    cout << "\n";
    for(auto element : decode)
    {
        cout << element.first << " " << element.second << "\n";
    }
    */
    return 0;
}
