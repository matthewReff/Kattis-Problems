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
#include <set>
#include <math.h>

typedef long long ll;
using namespace std;


int main()
{
	ll i, j, k;
	string testString;
	string compString = "problem";
	while (getline(cin, testString))
	{
		transform(testString.begin(), testString.end(), testString.begin(), ::tolower);
		size_t found = testString.find(compString);
		if (found != string::npos)
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




