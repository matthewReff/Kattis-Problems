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
    ull i, j, k;

    ll words, wordLength;
    ll top, left, right, bottom;

    vector<string> board;
    vector<string> wordList;
    string temp;
    cin >> words >> wordLength;
    cin >> top >> left >> right >> bottom;

    for (i = 0; i < words; i++)
    {
        cin >> temp;
        wordList.push_back(temp);
    }

    board.resize(words + top + bottom);
    for (i = 0; i < (words + top + bottom); i++)
    {
        board[i].resize(left + right + wordLength);
    }

    for (i = 0; i < (words + top + bottom); i++)
    {
        for (j = 0; j < (left + right + wordLength); j++)
        {
            if ((i + j) % 2 == 0)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = '.';
            }
        }
    }

    for (i = 0; i < wordList.size(); i++)
    {
        for (j = 0; j < wordList[i].size(); j++)
        {
            board[i + top][j + left] = wordList[i][j];
        }
    }

    for (i = 0; i < board.size(); i++)
    {
        cout << board[i] << "\n";
    }


    return 0;
}
