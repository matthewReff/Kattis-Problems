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
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll inputVars;
    string TF;
    cin >> inputVars;
    vector<char> inputs;
    map<char, bool> truthVals;

    for(int i = 0; i < inputVars; i++)
    {
    	cin >> TF;
    	if(TF == "T")
    	{
    		truthVals['A'+i] = true;
    	}
    	else
    	{
    		truthVals['A'+i] = false;
    	}
    }

    char thing;
    while(cin >> thing)
    {
    	inputs.push_back(thing);
    }


    stack<bool> evalStack;
    for(int i = 0; i < inputs.size(); i++)
    {
    	if(inputs[i] == '-' || inputs[i] == '*' || inputs[i] == '+')
    	{
    		switch(inputs[i])
    		{
    			case '-':
    				{
    					bool thisVal = evalStack.top();
    					evalStack.pop();
    					evalStack.push(!thisVal);
    					break;
    				}
    				case '*':
    				{
    					bool firstVal = evalStack.top();
    					evalStack.pop();
    					bool secondVal = evalStack.top();
    					evalStack.pop();
    					evalStack.push(firstVal & secondVal);
    					break;
    				}
    				case '+':
    				{
    					bool firstVal = evalStack.top();
    					evalStack.pop();
    					bool secondVal = evalStack.top();
    					evalStack.pop();
    					evalStack.push(firstVal | secondVal);
    					break;
    				}
    		}
    	}
    	else
    	{
    		evalStack.push(truthVals[inputs[i]]);
    	}
    }
    if(evalStack.top())
    {
    	cout << "T";
    }
    else
    {
    	cout << "F";
    }
    return 0;
}
