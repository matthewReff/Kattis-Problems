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
    
    ll x, y;
    ll rows, cols, cells;
    ll spacesLeft;
    ll days = 1;
    vector<pair<ll, ll> > previousCoordPairs;
    vector<pair<ll, ll> > nextCoordPairs;
    
    cin >> rows >> cols >> cells;
    vector< vector<bool> > map(rows);
    for(i = 0; i < rows; i++)
    {
        map[i].resize(cols, false);
    }
    
    spacesLeft = rows * cols;
    for(i = 0; i < cells; i++)
    {
        cin >> x >> y;
        x -= 1;
        y -= 1;
        if (!map[x][y])
        { 
            map[x][y] = true;
            previousCoordPairs.push_back(make_pair(x,y));
            spacesLeft--;
        }  
    }
    while(spacesLeft > 0)
    {
        days++;
        for(i = 0; i < previousCoordPairs.size(); i++)
        {
            ll tempI, tempJ;
            for(j = 0; j < 4; j++)
            {
                switch(j)
                {
                    case 0:
                        tempI = previousCoordPairs[i].first;
                        tempJ = previousCoordPairs[i].second + 1;
                        break;
                    case 1:
                        tempI = previousCoordPairs[i].first;
                        tempJ = previousCoordPairs[i].second - 1;
                        break;
                    case 2:
                        tempI = previousCoordPairs[i].first + 1;
                        tempJ = previousCoordPairs[i].second;
                        break;
                    case 3:
                        tempI = previousCoordPairs[i].first - 1;
                        tempJ = previousCoordPairs[i].second;
                        break;
                };
                if (tempI >= 0 && tempJ >= 0 && tempI < rows && tempJ < cols && !map[tempI][tempJ])
                {
                    nextCoordPairs.push_back(make_pair(tempI, tempJ));
                    map[tempI][tempJ] = true;
                    spacesLeft--;    
                }    
            }    
        }
        previousCoordPairs.clear();
        for(auto coordPair : nextCoordPairs)
        {
            previousCoordPairs.push_back(coordPair);
        }
        nextCoordPairs.clear();
        
        /*
        for(j = 0; j < rows; j++)
        {
            for(k = 0; k < cols; k++)
            {
                if (map[j][k])
                {
                    cout << '+';
                }
                else
                {
                    cout << "-";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        */
    }
    cout << days << "\n";
    
    return 0;
}
