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

int GetAsciiVal(char letter);
char GetCharFromInt(int num);

int main()
{
    ll i, j, k;
    ll cases;
    char type;
    string inputstring; 
    string result = "";

    cin >> cases;
    cin.ignore();
    for(i = 0; i < cases; i++)
    {
    	getline(cin, inputstring);
    	type = inputstring[0];
    	inputstring = inputstring.substr(2);
    	result = inputstring[0];

    	if(type == 'e')
    	{
    		for(j = 1; j < inputstring.length(); j++)
    		{
    			int prevAsciiVal = GetAsciiVal(result[result.length()-1]);
    			int currentAsciiVal = GetAsciiVal(inputstring[j]);
    			result += GetCharFromInt(prevAsciiVal + currentAsciiVal);
    		}
    	}
    	else
    	{
    		for(j = 1; j < inputstring.length(); j++)
    		{
    			char prevChar = result.back();
    			int lastCharVal = GetAsciiVal(inputstring[j-1]);
    			int currentCharVal = GetAsciiVal(inputstring[j]);
    			if( lastCharVal < currentCharVal)
    			{
    				char newChar = GetCharFromInt(currentCharVal - lastCharVal);
    				result += newChar;
    			}
    			else
    			{
    				char newChar = GetCharFromInt(27 + currentCharVal - lastCharVal);
    				result += newChar;
    			}
    		}
    	}
    	cout << result << "\n";
    }
    return 0;
}

int GetAsciiVal(char letter)
{
	if(letter == ' ')
	{
		return 0;
	}
	else
	{
		return (letter - 'a')+ 1;
	}
}

char GetCharFromInt(int num)
{
	num %= 27;
	if(num == 0)
	{
		return ' ';
	}
	else
	{
		return 'a' + num - 1;		
	}
}