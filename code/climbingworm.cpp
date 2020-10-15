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
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
 	ll a, b, c;
ll days = 0;
ll current = 0;
	cin >> a >> b >> c;

while(current < c)
{
	current += a;
	days++;
if(current < c)
{
	current -= b;
}


}

	cout << days << "\n";   
    return 0;
}
