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

	ll trees;
	ll days;
	ll totalDays = 0;
	ll * forest;

	cin >> trees;

	forest = new(nothrow) ll[trees];

	for (i = 0; i < trees; i++)
	{
		cin >> forest[i];
	}

	sort(forest, forest + trees);
	reverse(forest, forest + trees);


	for (i = 0; i < trees; i++)
	{
		if (forest[i] + i> totalDays)
		{
			totalDays = forest[i] + i;
		}
	}
	cout << totalDays + 2;
	return 0;
}