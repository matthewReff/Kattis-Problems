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
    
    ll totalQueens = 0;
    vector<string> board(8);
    vector<bool> upRight(14, false);
    vector<bool> upLeft(14, false);
    vector<bool> row(8, false);
    vector<bool> col(8, false);

    string conString = "";
    bool valid = true;

    for (i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    for (auto myString : board)
    {
        for (auto myChar : myString)
        {
            if (myChar == '*')
            {
                totalQueens++;
            }
        }
    }

    if (totalQueens != 8)
    {
        valid = false;
    }
    
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == '*')
            {
                if (!upRight[i + j])
                {
                    upRight[i + j] = true;
                }
                else
                {
                    valid = false;
                }
                if(!row[i])
                {
                    row[i] = true;
                }
                else
                {
                    valid = false;
                }
                if(!col[j])
                {
                    col[j] = true;
                }
                else
                {
                    valid = false;
                }
            }
        }
    }

    for (i = 0; i < 8; i++)
    {
        reverse(board[i].begin(), board[i].end());
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == '*')
            {
                if (!upLeft[i + j])
                {
                    upLeft[i + j] = true;
                }
                else
                {
                    valid = false;
                }
            }
        }
    }

    if (!valid)
    {
        cout << "invalid\n";
    }
    else
    {
        cout << "valid\n";
}
    
    return 0;
}
