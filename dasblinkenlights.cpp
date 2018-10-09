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

typedef long long ll;
using namespace std;

ll gcd( ll a, ll b);
ll lcm(ll a, ll b);
int main()
{
	ll i, j, k;
	
	ll a, b, c;
	cin >> a >> b >> c;
	if (lcm(a, b) <= c)
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}
	return 0;
}
ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
ll lcm(ll a, ll b)
{
	return (a * b / gcd(a, b));
}


