#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <queue>
#include <map>
#include <numeric>
#include <set>

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	
	ll cases;
	ll r, p, d;
	pair < string, double> temp;
	double garb;
	double base;
	

	cout << fixed << setprecision(1);
	cin >> cases;
	for (i = 0; i < cases; i++)
	{
		vector<pair<string, double>> ingredients;
		cin >> r >> p >> d;
		for (j = 0; j < r; j++)
		{
			cin >> temp.first;
			cin >> garb;
			
			cin >> temp.second;
			if (temp.second == 100)
			{
				base = garb;
			}
			ingredients.push_back(temp);
		}
		cout << "Recipe # " << i + 1 << "\n";
		for (j = 0; j < r; j++)
		{
			cout << ingredients[j].first << " " << 
				ingredients[j].second / 100.0 * base * double(d) / double(p) << "\n";
		}
		cout << "----------------------------------------\n";
	}
}


