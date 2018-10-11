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
#include <set>

typedef long long ll;
using namespace std;

int main()
{
    ll i, j, k;
    ll initial;
    ll turn;    
    ll temp;
    cin >> initial >> turn;
    
    if (360 - abs(turn - initial) >
            abs(turn - initial))
    {
       temp = abs(turn - initial);  
    }
    else
    {
        temp = 360 - abs(turn - initial);
    }
    
    if ((initial + temp ) % 360 == turn)
    {
        cout << temp << "\n";
    }
    else
    {
        cout << -temp << "\n";
    }
    return 0;
}
