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

	string inputString;
	cin >> inputString;

	string currentString = "";
	stack<ll> pstack;
	for(i = 0; i < inputString.size(); i++)
	{
		currentString += inputString[i];
		if(currentString == "SS")
		{
			string numString = "";
			i++;
			while(inputString[i] != 'N')
			{
				if(inputString[i] == 'T')
				{
					numString += '1';
				}
				else
				{
					numString += '0';
				}
				i++;
			}
			ll newNum = stoi(numString.substr(1), nullptr, 2);
			if(numString[0] == '1')
			{
				newNum *= -1;
			}
			pstack.push(newNum);
			currentString.clear();
		}
		else if(currentString == "SNS")
		{
			if(pstack.size() >= 1)
			{
				pstack.push(pstack.top());
			}
			else
			{
				cout << "Invalid copy operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "SNT")
		{
			if(pstack.size() >= 2)
			{
				ll elem1 = pstack.top();
				pstack.pop();
				ll elem2 = pstack.top();
				pstack.pop();
				pstack.push(elem1);
				pstack.push(elem2);
			}
			else
			{
				cout << "Invalid swap operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "SNN")
		{
			if(pstack.size() >= 1)
			{
				pstack.pop();
			}
			else
			{
				cout << "Invalid remove operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "TSSS")
		{
			if(pstack.size() >= 2)
			{
				ll elem1 = pstack.top();
				pstack.pop();
				ll elem2 = pstack.top();
				pstack.pop();
				pstack.push(elem2 + elem1);
			}
			else
			{
				cout << "Invalid addition operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "TSST")
		{
			if(pstack.size() >= 2)
			{
				ll elem1 = pstack.top();
				pstack.pop();
				ll elem2 = pstack.top();
				pstack.pop();
				pstack.push(elem2 - elem1);
			}
			else
			{
				cout << "Invalid subtraction operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "TSSN")
		{
			if(pstack.size() >= 2)
			{
				ll elem1 = pstack.top();
				pstack.pop();
				ll elem2 = pstack.top();
				pstack.pop();
				pstack.push(elem2 * elem1);
			}
			else
			{
				cout << "Invalid multiplication operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "TSTS")
		{
			if(pstack.size() >= 2)
			{
				ll elem1 = pstack.top();
				if(elem1 == 0)
				{
					cout << "Division by zero\n";
				}
				else
				{
					pstack.pop();
					ll elem2 = pstack.top();
					pstack.pop();
					pstack.push(elem2 / elem1);
				}
			}
			else
			{
				cout << "Invalid division operation\n";
			}
			currentString.clear();
		}
		else if(currentString == "TNST")
		{
			if(pstack.size() >= 1)
			{
				cout << pstack.top() << "\n";
				pstack.pop();
			}
			else
			{
				cout << "Invalid print operation\n";
			}
			currentString.clear();
		}
	}    
    return 0;
}
