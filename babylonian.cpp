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
#include <unordered_map>

#define EPSILON 0.00001
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;


vector<string> pySplit(string & splitString, char seperator = ' ')
{
    int endIndex = 0;
    vector<string > seperated;
    seperated.push_back("");
    for (unsigned int i = 0; i < splitString.size(); i++)
    {
        if (splitString[i] == seperator)
        {
            endIndex++;
            seperated.push_back("");
        }
        else
        {
            seperated[endIndex] += splitString[i];
        }
    }
    return seperated;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ull i, j, k;
    
    ll cases;
    ld bookX, bookY, candleX, candleY;
    ll candles;
    string babText;
    vector<string> decoded;
    cin >> cases;

    for (i = 0; i < cases; i++)
    {
        cin >> babText;
        decoded = pySplit(babText, ',');
        //cout << decoded.size() << "\n";
        ll total = 0;
        ll num;
        for (j = 0; j < decoded.size(); j++)
        {
            if (decoded[j] != "")
            {
                num = stoi(decoded[j]);
            }
            else
            {
                num = 0;
            }
            num *= pow(60, decoded.size() - j - 1);
            total += num;
        }
        cout << total << "\n";
    }
    return 0;
}
