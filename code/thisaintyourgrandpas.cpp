#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll boardSize;
    cin >> boardSize;

    vector<string> board(boardSize);
    bool valid = true;
    for(i = 0; i < boardSize; i++)
    {
    	cin >> board[i];
    }

    
    for(i = 0; i < boardSize; i++)
    {
    	ll totalBlack = 0;
	    ll totalWhite = 0;
	    ll inARow = 1;
	    ll lastChar = 'p';
    	for(j = 0; j < boardSize; j++)
    	{
    		if(board[i][j] == 'W')
    		{
    			totalWhite++;
    		}
    		else
    		{
    			totalBlack++;
    		}

    		if(lastChar != board[i][j])
    		{
    			lastChar = board[i][j];
    			inARow = 1;
    		}
    		else
    		{
    			inARow++;
    			if(inARow >= 3)
    			{
    				valid = false;
    			}
    		}
    	}

    	if(totalWhite != totalBlack)
    	{
    		valid = false;
    	}
    }
    
    for(i = 0; i < boardSize; i++)
    {
    	ll totalBlack = 0;
	    ll totalWhite = 0;
	    ll inARow = 1;
	    ll lastChar = 'p';
    	for(j = 0; j < boardSize; j++)
    	{
    		if(board[j][i] == 'W')
    		{
    			totalWhite++;
    		}
    		else
    		{
    			totalBlack++;
    		}

    		if(lastChar != board[j][i])
    		{
    			lastChar = board[j][i];
    			inARow = 1;
    		}
    		else
    		{
    			inARow++;
    			if(inARow >= 3)
    			{
    				valid = false;
    			}
    		}
    	}

    	if(totalWhite != totalBlack)
    	{
    		valid = false;
    	}
    }

    cout << valid << "\n";
    return 0;
}
