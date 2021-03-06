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
    
    ll itrs;
    string outString;
    string tempString;
    
    while(cin >> itrs)
    {
        cin.ignore();
        getline(cin, outString); 
        for(i = 0; i < itrs; i++)
        {
            tempString = "";
            for(auto letter : outString)
            {
                if((letter >= '!' && letter <= '*') || (letter >= '[' && letter <= ']'))
                {
                  tempString += '\\'; 
                }
                tempString += letter;
            }
            outString = tempString;
        }
        cout << outString << "\n";
    }
    
    return 0;
}
