#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;


int main()
{
	long long i, j, k;
	int cases, teams, score, sum;
	vector<int> members;
	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		members.clear();
		sum = 0;
		cin >> teams;
		for (j = 0; j < teams * 3; j++)
		{
			cin >> score;
			members.push_back(score);
		}
		sort(members.rbegin(), members.rend());
		for (j = 0; j < teams * 2; j++)
		{
			if (j % 2 == 1)
			{
				sum += members[j];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}