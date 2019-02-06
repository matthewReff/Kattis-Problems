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
    
    cout << fixed << setprecision(0);
    ll i, j, k;
    
    ull h;
    string path;
    vector<string> args;
    ll currentLoc = 1;
    getline(cin, path);
    args = pySplit(path);
    if(args.size() == 1)
    {
        h = stoi(args[0]);
    }
    else
    {
        h = stoi(args[0]);
        path = args[1];
    }
    for(auto letter : path)
    {
        if(letter == 'L')
        {
            currentLoc *= 2;
        }
        else
        {
            currentLoc *= 2;
            currentLoc++;
        }
    }
    
    //cout << currentLoc << "\n";
    h = pow(2, h);
    h *= 2;
    cout << h - currentLoc << "\n";
    return 0;
}
