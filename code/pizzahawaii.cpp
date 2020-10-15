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
	ll cases;
	ll pizzaNum;
	string garb, temp;
	ll ingredients;
	
	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		vector<pair < vector< string >, vector < string > > > pizzas;
		vector<pair < string, string > > possiblePairs;
		set <pair < string, string > > legitPairs;
		cin >> pizzaNum;
		for (j = 0; j < pizzaNum; j++)
		{
			vector<string> foreign;
			vector<string> native;
			cin >> garb;
			cin >> ingredients;
			for (k = 0; k < ingredients; k++)
			{
				cin >> temp;
				foreign.push_back(temp);
			}
			cin >> ingredients;
			for (k = 0; k < ingredients; k++)
			{
				cin >> temp;
				native.push_back(temp);
			}

			pizzas.push_back(make_pair(foreign, native));
			//end of individual pizza
		}
		
		for (j = 0; j < pizzaNum; j++)
		{
			for (k = 0; k < pizzas[j].first.size(); k++)
			{
				for (int l = 0; l < pizzas[j].second.size(); l++)
				{
					possiblePairs.push_back(make_pair(pizzas[j].first[k], pizzas[j].second[l]));
				}
			}
		}
		//after all pizzas
		//for each pair in a pizza, 
		//if no other pizzas have only one element of the combo, add it to a set
		for (j = 0; j < possiblePairs.size(); j++)
		{

			
			bool valid = true;
			for (k = 0; k < pizzaNum; k++)
			{
				bool found1 = false;
				bool found2 = false;
				for (int l = 0; l < pizzas[k].first.size(); l++)
				{
					if (possiblePairs[j].first == pizzas[k].first[l])
					{
						found1 = true;
					}
				}
				for (int l = 0; l < pizzas[k].second.size(); l++)
				{
					if (possiblePairs[j].second == pizzas[k].second[l])
					{
						found2 = true;
					}
				}
				valid = valid && !(found1 ^ found2);
			}
			if (valid)
			{
				legitPairs.insert(possiblePairs[j]);
			}
		}
		for (auto YES : legitPairs)
		{
			cout << "(" << YES.first << ", " << YES.second << ")\n";
		}
		cout << "\n";
	}
	return 0;
}
