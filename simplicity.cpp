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

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	string myString;
	map <char, ll> freq;
	vector<ll> myArr;
	ll total = 0;
	cin >> myString;

	for (auto littleChar : myString)
	{
		freq[littleChar]++;
	}

	
	for (auto thing : freq)
	{
		myArr.push_back(thing.second);
	}
	sort(myArr.rbegin(), myArr.rend());

	for (i = 2; i < myArr.size(); i++)
	{
		total += myArr[i];
	}

	cout << total << "\n";

	return 0;
}


