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
    
    ll rows, cols;
    ll currentX, currentY;
    ll totalSteps;
    cin >> rows >> cols;
    vector<string> map(rows);
    vector<vector<bool>> visited(rows);
    
    for(i = 0; i < rows; i++)
    {
        cin >> map[i];
        visited[i].resize(cols, false);
    }
    currentX = 0;
    currentY = 0;
    totalSteps = 0;
    while(!visited[currentX][currentY])
    {
        char tileVal = map[currentX][currentY];
        //cout << tileVal << "\n";
        visited[currentX][currentY] = true;
        switch(tileVal)
        {
            
            case 'N':
                currentX -=1;
                break;
            case 'S':
                currentX +=1;
                break;
            case 'W':
                currentY -= 1;
                break;
            case 'E':
                currentY += 1;
                break;
            case 'T':
                cout << totalSteps << "\n";
                return 0;
                break;
        };
        if(currentX < 0 || currentX >= rows || currentY < 0 || currentY >= cols)
        {
            cout << "Out\n";
            return 0;
        }
        totalSteps++;    
    }
    
    cout << "Lost\n";    
    return 0;
}
