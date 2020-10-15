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
#include <stack>
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    vector<bool> valids(10001, false);
    ll year;
    
    ll temp = 24219;
    while(temp / 12 < 10001)
    {
        //cout << temp << "\n";
        valids[(temp / 12)] = true;
        temp += 26;
    }
    //cout << valids[2018] << "\n";
    cin >> year;
    if(valids[year])
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}


