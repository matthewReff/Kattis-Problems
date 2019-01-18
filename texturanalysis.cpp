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
    
    ll whiteSpace;
    ll stepper;
    ll caseNum = 1;
    string texture;
    bool even;
    while(cin >> texture && texture != "END")
    {
        even = true;
        if(texture.size() == 1)
        {
            cout << caseNum << " EVEN\n";
            caseNum++;
            continue;
        }
        else
        {
            stepper = 1;
            while(texture[stepper] != '*')
            {
                stepper++;
            }
            whiteSpace = stepper;
        }
        
        for(i = 0; i < texture.size(); i++)
        {
            if(whiteSpace != 0 && i % whiteSpace != 0)
            {
                if (texture[i] != '.')
                {
                    even = false;   
                }
            }
            else
            {
                if (texture[i] != '*')
                {
                    even = false;
                }
            }
        }
        
        cout << caseNum << " ";
        if(even)
        {
            cout << "EVEN\n";
        }
        else
        {
            cout << "NOT EVEN\n";
        }
        caseNum++;
    }
    return 0;
}


