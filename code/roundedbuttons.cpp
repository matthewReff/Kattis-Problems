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

ld dist(ld Xcoord1, ld Ycoord1, ld Xcoord2, ld Ycoord2)
{
    return sqrt((Xcoord1 - Xcoord2) * (Xcoord1 - Xcoord2) + (Ycoord1 - Ycoord2) * (Ycoord1 - Ycoord2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll cases;
    ld x, y, w, h, r, m;
    ld queryX, queryY;
    
    cin >> cases;
    
    for(i = 0; i < cases; i++)
    {
        cin >> x >> y >> w >> h >> r >> m;
        
        //chop of left/right rouded sides
        
        for(j = 0; j < m; j++)
        {
            cin >> queryX >> queryY;
            //if completely outside rectangle
            if(queryY < y || y + h < queryY || queryX < x || x+ w <queryX )
            {
                cout << "outside\n";
            }
            //if inside rectangle and not near edges
            else if(queryX >= (x + r) && queryX <= (x + w - r))
            {
                cout << "inside\n";
            }
            //if near edge but not on upper side
            else if (queryY >= ( y + r) && queryY <= (y + h - r))
            {
                cout << "inside\n";
            }
            else
            {
                if(  dist(x + r, y + r, queryX, queryY) <= r + EPSILON ||
                     dist(x + r, y + h - r, queryX, queryY) <= r + EPSILON  ||
                     dist(x + w - r, y + r, queryX, queryY) <= r + EPSILON  ||
                     dist(x + w - r, y + h - r, queryX, queryY) <= r + EPSILON )
                 {
                    cout << "inside\n";
                 }
                 else
                 {
                    cout << "outside\n";
                 }
            }
              
        }
        cout << "\n";
    }
    
    return 0;
}
