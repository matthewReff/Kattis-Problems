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

ll valueConverter(char num)
{
	if(num >= 'a' && num <= 'z')
	{
		return num - 'a' + 10;
	}
	else if(num == '0')
	{
		return 2;
	}
	else
	{
		return num - '0';
	}
}

int main()
{
    ll i;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll cases;
    cin >> cases;

    for(i = 0; i < cases; i++)
    {
    	string num1Str, num2Str, answerStr;
    	char op, garb;
    	cin >> num1Str >> op >> num2Str >> garb >> answerStr;
    	bool foundOne = false;
    	ll minBase = 1;

    	for(auto subChar : num1Str)
    	{
    		minBase = max(minBase, valueConverter(subChar));

    	}
    	for(auto subChar : num2Str)
    	{
    		minBase = max(minBase, valueConverter(subChar));

    	}
    	for(auto subChar : answerStr)
    	{
    		minBase = max(minBase, valueConverter(subChar));

    	}

    	for(ll j = minBase; j <= 36; j++)
    	{
    		try{
    			ll num1; 
    			ll num2;
    			ll answer;
    			if(j == 1)
    			{
					num1 = num1Str.size();
	    			num2 = num2Str.size();
	    			answer = answerStr.size();
    			}
    			else
    			{
		    		num1 = stoi(num1Str, nullptr, j);
		    		num2 = stoi(num2Str, nullptr, j);
		    		answer = stoi(answerStr, nullptr, j);
		    	}
	    		/*
	    		cout << "num1: " << num1 << "\n";
	    		cout << " num2: " << num2 << "\n";
	    		cout << "answer: " << answer << "\n";
	    		*/
	    		bool valid = false;
	    		switch(op)
	    		{
	    			case '+':
	    			{
	    				valid = num1 + num2 == answer;
	    				break;
	    			}
	    			case '-':
	    			{
	    				valid = num1 - num2 == answer;
	    				break;
	    			}
	    			case '*':
	    			{
	    				valid = num1 * num2 == answer;
	    				break;
	    			}
	    			case '/':
	    			{
	    				ll temp = num1 / num2;
	    				temp *= num2;
	    				//check that the numbers cleanly divide, and then blindly integer divide
	    				valid = temp == num1 && num1 / num2 == answer;
	    				break;
	    			}
	    		}
	    		if(valid)
	    		{
	    			foundOne = true;
		    		if(j >= 10 && j != 36)
		    		{
		    			cout << char('a'+j-10);
		    		}
		    		else if(j == 36)
		    		{
		    			cout << 0;
		    		}
		    		else
		    		{
		    			cout << j;
	    			}
    			}
    		}
    		catch(exception& e)
    		{

    		}
    	}
    	if(!foundOne)
    	{
    		cout << "invalid";
    	}
    	cout << "\n";
    }
    return 0;
}
//Start: Mon Jan 27 15:32:31 MST 2020
//Stop: Mon Jan 27 16:45:52 MST 2020
//Start: Wed Jan 29 09:18:48 MST 2020
//Stop: Wed Jan 29 09:30:44 MST 2020
