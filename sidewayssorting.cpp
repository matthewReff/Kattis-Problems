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

bool insensitive(string left, string right)
{
    for(int i = 0 ; i < left.size(); i++)
    {
        if(tolower(left[i]) < tolower(right[i]))
        {
            return true;
        }
        else if (tolower(left[i]) > tolower(right[i]))
        {
            return false;
        }
        
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i, j, k;
    
    ll rows, cols;
    
    while(cin >> rows >> cols && rows != 0 || cols != 0)
    {
        vector<string> grid(rows);
        for(i = 0; i < rows; i++)
        {
            cin >> grid[i];
        }
        vector<string> rotated(cols);
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                rotated[j] += grid[i][j];
            }
        }
        
        
        sort(rotated.begin(), rotated.end(), insensitive);
        /*
        for(auto thing : rotated)
        {
            cout << thing << "\n";
        }
        */
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                grid[i][j] = rotated[j][i];
            }
        }
        
        for(auto line : grid)
        {
            cout << line << "\n";
        }
        cout << "\n";   
    }
    
    return 0;
}
