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
	
	ll noms;
	ll temp;
	set<ll> unqiues;
	vector<pair< ll, ll > > atk;
	vector<pair< ll, ll > > def;
	vector<pair< ll, ll > > hp;
	cin >> noms >> k;

	for (i = 0; i < noms; i++)
	{
		cin >> temp;
		atk.push_back(make_pair(temp, i));
		cin >> temp;
		def.push_back(make_pair(temp, i));
		cin >> temp;
		hp.push_back(make_pair(temp, i));
	}

	sort(atk.rbegin(), atk.rend());
	sort(def.rbegin(), def.rend());
	sort(hp.rbegin(), hp.rend());

	for (i = 0; i < k; i++)
	{
		unqiues.insert(atk[i].second);
		unqiues.insert(def[i].second);
		unqiues.insert(hp[i].second);
	}

	cout << unqiues.size() << "\n";
	return 0;
}
