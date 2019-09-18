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

double GetDistance(pair<double, double> first, pair<double, double> second);
map<ll, ll> primeFactors(int n);

int main()
{
	map<string, int> subStrings;

	string sequence;
	cin >> sequence;

	for (int span = 2; span < sequence.size()/2; span++)
	{
		for (int i = 0; i < sequence.size() - span; i++)
		{
			string checkString = sequence.substr(i, span);
			if (subStrings.find(checkString) == subStrings.end())
			{
				for (int j = 0; j <= sequence.size() - span; j++)
				{
					string thing = sequence.substr(j, span);       
					if (checkString == thing)
					{
						subStrings[checkString]++;
						j += span - 1;
					}
				}
			}
		}
	}

	int minChars = sequence.length();
	for (auto thing : subStrings)
	{
		string thisMacro = thing.first;
		int macroUses = thing.second;
		//cout << thisMacro << " " << macroUses << "\n";
		int charsNeeded = sequence.length() - (macroUses * (thisMacro.size() - 1)) + thisMacro.size();
		//cout << thing.first << " " << charsNeeded << "\n";
		minChars = min(minChars, charsNeeded);
	}

	cout << minChars << "\n";
	return 0;
}

map<ll, ll> primeFactors(int n)
{
	map<ll, ll> factors;
	// Print the number of 2s that divide n  
	while (n % 2 == 0)
	{
		factors[2]++;
		n = n / 2;
	}

	// n must be odd at this point. So we can skip  
	// one element (Note i = i +2)  
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n  
		while (n % i == 0)
		{
			factors[i]++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n  
	// is a prime number greater than 2  
	if (n > 2)
		factors[n]++;

	return factors;
}

double GetDistance(pair<double, double> first, pair<double, double> second)
{
	return sqrt(((first.first - second.first) * (first.first - second.first)) +
		((first.second - second.second) * (first.second - second.second)));
}
