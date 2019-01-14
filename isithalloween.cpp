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

typedef long long ll;
using namespace std;

int main()
{
	ll i, j, k;
	string a;
	int n;
	cin >> a >> n;

	if (a == "OCT" && n == 31)
	{
		cout << "yup\n";
	}
	else if (a == "DEC" && n == 25)
	{
		cout << "yup\n";
	}
	else
	{
		cout << "nope\n";
	}
	return 0;
}
