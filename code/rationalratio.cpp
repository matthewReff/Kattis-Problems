#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <map>
typedef long long ll;
using namespace std;



int main()
{
    double decimal;
    ll decimalLoc;
    ll nonRepeat;
    ll n , d;
    string decimalString;
    string::iterator sItr;
    ll repeating;
    cin >> decimalString;
    cin >> repeating;
    sItr = find(decimalString.begin(), decimalString.end(), '.');
    decimalLoc =  sItr - decimalString.begin();
    ll intPart;
    intPart = stoll(decimalString.substr(0, decimalLoc));
    nonRepeat = decimalString.size() - decimalLoc - repeating - 1;
    
    d = pow(10, decimalString.size() - decimalLoc - 1) - pow(10, nonRepeat);
    n = stoll(decimalString.substr(decimalLoc + 1, (repeating + nonRepeat)));
    if (nonRepeat != 0)
    {
        n -= stoll(decimalString.substr(decimalLoc + 1, nonRepeat));
    }
    n += (d*intPart);
    ll g  = __gcd(n, d);
    cout << n/g << "/" << d/g << "\n";
    return 0;
}
