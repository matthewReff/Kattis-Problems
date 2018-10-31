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
#include <set>

typedef long long ll;
using namespace std;

int main()
{
	ll i, j, k;
	ll cat;
	ll temp;
	ll parent;
	ll root;
	ll current;
	deque<ll> bfs;
	bool foundRoot = false;

	cin >> cat;

	map <ll, ll> parents;
	map<ll, ll>::iterator itr;


	while (cin >> temp && temp != -1)
	{
		parent = temp;
		while (cin.peek() != '\n')
		{
			cin >> temp;
			parents[temp] = parent;
			
		}
	}
	cout << cat << " ";
	current = cat;
	while (parents.find(current) != parents.end())
	{
		current = parents[current];
		cout << current << " ";
	}
	return 0;
}
