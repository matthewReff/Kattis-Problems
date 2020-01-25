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

    string Y, P;
    cin >> Y >> P;
    char lastChar = Y[Y.size() - 1];

    if(lastChar == 'e')
    {
    	cout << Y << "x" << P << "\n";
    }
    else if(lastChar == 'a' || lastChar == 'i' || lastChar == 'o' || lastChar == 'u')
    {
    	cout << Y.substr(0, Y.size()-1) << "ex" << P << "\n";
    }
    else if(Y[Y.size() -1] == 'x' && Y[Y.size() -2] == 'e')
    {
    	cout << Y << P << "\n";

    }
    else
    {
    	cout << Y << "ex" << P << "\n";
    }
    return 0;
}
