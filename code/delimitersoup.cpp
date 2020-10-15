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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll size;
    cin >> size;
    cin.ignore();
    string inputString;
    getline(cin, inputString);
    stack<char> vals;

    for(i = 0; i < inputString.size(); i++)
    {
    	char thisChar = inputString[i];
    	if(thisChar == '(')
    	{
    		vals.push(thisChar);
    	}
    	else if(thisChar == '[')
    	{
    		vals.push(thisChar);
    	}
    	else if(thisChar == '{')
    	{
    		vals.push(thisChar);
    	}
    	else if(thisChar == ')')
    	{
    		if(vals.size() == 0 || vals.top() != '(')
    		{
    			cout << thisChar << " " << i << "\n";
    			return 0;
    		}
    		vals.pop();
    	}
    	else if(thisChar == ']')
    	{
    		if(vals.size() == 0 ||vals.top() != '[')
    		{
    			cout << thisChar << " " << i << "\n";
    			return 0;
    		}
    		vals.pop();
    	}
    	else if(thisChar == '}')
    	{
    		if(vals.size() == 0 || vals.top() != '{')
    		{
    			cout << thisChar << " " << i << "\n";
    			return 0;
    		}
    		vals.pop();
    	}
    }
    cout << "ok so far\n";
    return 0;
}
