// Implemented by me, solution by https://open.kattis.com/users/gabriel-hofer
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
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// Can be though of as splitting the graph into two sections by selecting a vertex and then sweeping
// through the other possible connections
// This same amount generated is the same for each of the n points, so multiply by n
// Then, we've counted each point 4 times?
int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;


    ll value = 0;
    ll max = n - 2;
    for(int i = 1; i <= max; i++)
    {
    	value += i * (max-i);
    }
    value *= n;
    value /= 4;

    cout << value << "\n";
    return 0;
}
