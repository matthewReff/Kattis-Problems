#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	ll num;
	cin >> num;

	switch(num){
		case 2:
		case 6:
		case 10:
			cout << "Odd\n";
			break;
		case 4:
		case 8:
			cout << "Even\n";
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
			cout << "Either\n";
			break;
		};
    return 0;
}
