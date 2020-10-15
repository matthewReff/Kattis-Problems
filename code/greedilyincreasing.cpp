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
#include <ctime>

using namespace std;
typedef long long ll;

int main()
{
	ll i, j, k;

	ll nums;
	ll num;
	ll curr;
	vector<ll> greedy;
	vector<ll> in;

	cin >> nums;

	for (i = 0; i < nums; i++)
	{
		cin >> num;
		in.push_back(num);
	}

	greedy.push_back(in[0]);
	curr = in[0];

	for (i = 1; i < nums; i++)
	{
		if (in[i] > curr)
		{
			greedy.push_back(in[i]);
			curr = in[i];
		}
	}

	cout << greedy.size() << "\n";

	for (i = 0; i < greedy.size(); i++)
	{
		cout << greedy[i] << " ";
	}
	return 0;
}