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

    ll conversions;
    ll intermediate;
    ll highestBase;
    ll temp;
    string baseNum, alienLang, convertLang;
    map<char, int> alienConvert;
    map<int, char> langConvert;

    cin >> conversions;

    for (i = 0; i < conversions; i++)
    {
        cin >> baseNum >> alienLang >> convertLang;
        for (j = 0; j < alienLang.size(); j++)
        {
            alienConvert[alienLang[j]] = j;
        }

        for (j = 0; j < convertLang.size(); j++)
        {
            langConvert[j] = convertLang[j];
        }

        intermediate = 0;
        for (j = baseNum.size() - 1; j >= 0; j--)
        {
            intermediate += alienConvert[baseNum[baseNum.size() - j - 1]] * pow(alienLang.size(), j);
        }

        highestBase = 0;
        while (pow(convertLang.size(), highestBase + 1) <= intermediate)
        {
            highestBase++;
        }
        
        string converted;
        for (j = highestBase; j >= 0; j--)
        {
            temp = convertLang.size() - 1;
            while (intermediate - (temp * pow(convertLang.size(), j)) < 0 && temp != 0)
            {
                temp--;
            }
            intermediate -= (temp * pow(convertLang.size(), j));
            converted += convertLang[temp];
        }
        
        cout << "Case #" << i+1 << ": " << converted << "\n";

    }

    return 0;
}
