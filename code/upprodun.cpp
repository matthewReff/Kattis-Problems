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

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll rooms, teams;

    cin >> rooms >> teams;

    int index = 0;
    vector<int> allocated(rooms, 0);
    while(teams)
    {
    	allocated[index]++;
    	teams--;
    	index++;
    	index %= rooms;
    }

    for(int i = 0; i < rooms; i++)
    {
    	cout << string(allocated[i], '*') << "\n";
    }
    return 0;
}
