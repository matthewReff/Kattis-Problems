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

    
    ll people;
    cin >> people;
    vector<ll> line(people, 1);
    ll loc;
    for(i = 2; i <= people; i++)
    {
    	cin >> loc;
    	line[loc+1] = i;
    }

    for(auto person : line)
    {
    	cout << person << " ";
    }
    return 0;
}
