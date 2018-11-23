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
using namespace std;

int main()
{
	ll i, j, k;
	string command;
	string varName;
	string left, right;
	int value;
	char op;
	ll output;
	map <string, int> vars;
	map < string, int>::iterator itr;
	while (cin >> command)
	{
		if (command == "define")
		{
			cin >> value >> varName;
			vars[varName] = value;
		}
		else
		{
			cin >> left >> op >> right;
			if (vars.find(left) == vars.end() || vars.find(right) == vars.end())
			{
				output = -1;
			}
			else if (op == '=')
			{
				output = (vars[left] == vars[right]);
			}
			else if (op == '>')
			{
				output = (vars[left] > vars[right]);
			}
			else if (op == '<')
			{
				output = (vars[left] < vars[right]);
			}
			

			if (output == -1)
			{
				cout << "undefined\n";
			}
			else if (output == 0)
			{
				cout << "false\n";
			}
			else
			{
				cout << "true\n";
			}
		}
	}
	return 0;
}
