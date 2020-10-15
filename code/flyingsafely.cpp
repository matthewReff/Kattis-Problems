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

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	
	ll cases;
	ll garb, num, edge;
	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		cin >> edge >> num;
		for (j = 0; j < num; j++)
		{
			cin >> garb >> garb;
		}
		cout << edge - 1 << "\n";
	}
	return 0;
}


