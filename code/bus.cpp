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
	ll i, j, k, l;
	
	ll cases, n;
	ll answer;

	cin >> cases;

	for (i = 0; i < cases; i++)
	{
		answer = 0;
		cin >> n;
		for (j = 0; j < n; j++)
		{
			answer *= 2;
			answer += 1;
			
		}
		cout << int(answer) << "\n";
	}
	return 0;
}