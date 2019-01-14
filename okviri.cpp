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
    string word;
    string fillString;
    vector<string> board(5);
    ll boardLength;
    
    cin >> word;
    boardLength = (((word.size() - 1) * 3) + word.size() + 4);
    //cout << ((word.size() - 1) * 3) << "\n";
    //cout << word.size() << "\n";
    //cout << 4 << "\n";
    //cout << boardLength;
    for(i = 0; i < boardLength; i++)
    {
        fillString += '.';
    }
    
    for(i = 0; i < 5; i++)
    {
        board[i] = fillString;
    }
    
    
    for(i = 2; i < boardLength; i+=4)
    {
        board[0][i] = '#';
        board[4][i] = '#';
    }
    for(i = 1; i < boardLength; i+=2)
    {
        board[1][i] = '#';
        board[3][i] = '#';
    }
    for(i = 0; i < boardLength; i+=4)
    {
        board[2][i] = '#';
    }
    for(i = 2; i < boardLength; i+=4)
    {
        board[2][i] = word[i/4];
    }
    
    
    for(i = 10; i < boardLength; i+=12)
    {
        board[0][i] = '*';
        board[4][i] = '*';
    }
    for(i = 9; i < boardLength; i+=12)
    {
        board[1][i] = '*';
        board[3][i] = '*';
    }
    for(i = 11; i < boardLength; i+=12)
    {
        board[1][i] = '*';
        board[3][i] = '*';
    }
    for(i = 8; i < boardLength - 1; i+=12)
    {
        
        board[2][i] = '*';
    }
    for(i = 12; i < boardLength; i+=12)
    {
        board[2][i] = '*';
    }
    
    
    
    for(auto line : board)
    {
        cout << line << "\n";
    }
    return 0;
}
