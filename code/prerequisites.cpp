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

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

bool onedFind(vector < ll > & arr, int element)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == element)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ull i, j, k;
	ll courses, catagories, cataNum, reqs, temp;
	while (cin >> courses >> catagories && courses != 0)
	{
		vector<ll> takenCourses (courses);
		vector<vector<ll> > courseList(catagories);
		vector<ll> courseReq(catagories);
		for (i = 0; i < courses; i++)
		{
			cin >> takenCourses[i];
		}
		
		for (i = 0; i < catagories; i++)
		{
			cin >> cataNum;
			cin >> courseReq[i];
			for (j = 0; j < cataNum; j++)
			{
				cin >> temp;
				courseList[i].push_back(temp);
			}
		}

		vector<ll> numCourses(catagories, 0);
		for (auto element : takenCourses)
		{
			for (i = 0; i < catagories; i++)
			{
				if (onedFind(courseList[i], element))
				{
					numCourses[i]++;
				}
			}
		}
		bool valid = true;
		for (i = 0; i < catagories; i++)
		{
			if (numCourses[i] < courseReq[i])
			{
				valid = false;
			}
		}
		if (valid)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}



	}
	return 0;
}
