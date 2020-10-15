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
    
    ll volume, size1, size2;
    ll bottlesSize1 = 0;
    ll bottlesSize2 = 0;
    
    cin >> volume >> size1 >> size2;
    for(i = volume / size1; i >= 0; i--)
    {
        j = volume - (i * size1);
        j /= size2;
        if (i * size1 + j * size2 == volume)
        {
            cout << i << " " << j << "\n";
            return 0;
        }    
    }
    cout << "Impossible\n";
    return 0;
}


