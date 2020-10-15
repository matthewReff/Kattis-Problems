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
    
    
    //nothing
    //            tails + 1
    // heads + 1, tails - 2
    // heads - 2, 
    
    
    //3 3
    //3 4
    //3 5
    //3 6
    //4 4
    //5 2
    //6 0
    //4 0
    //2 0
    //0 0
    ll steps;
    ll heads, tails;
    while(cin >> heads >> tails && (heads != 0 || tails != 0))
    {
        if(tails == 0)
        {
            cout << "-1\n";
            continue;
        }
        steps = 0;
        while(heads != 0 || tails != 0)
        {
            if(tails % 2 != 0)
            {
                //cout << "added one to tails\n";
                tails++;
                steps++;
            }
            else if((heads + tails / 2) % 2 != 0)
            {
                //cout << "added 2 to tails\n";
                tails += 2;
                steps += 2;
            }
            else
            {
                //cout << "chopped off all heads\n";
                heads += (tails / 2);
                steps += (tails / 2);
                tails = 0;
                steps += heads/2;
                heads = 0;
                    
            }    
        }
        cout << steps << "\n";
    }
    return 0;
}
