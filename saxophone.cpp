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
    
    map<char, vector<bool>> fingers;
    vector<ll> moves(8);
    vector<bool> lastFingers;
    string song;
    ll cases;
    
    
    fingers['c'] = {false, true, true, true, false, false, true, true, true, true};
    fingers['d'] = {false, true, true, true, false, false, true, true, true, false};
    fingers['e'] = {false, true, true, true, false, false, true, true, false, false};
    fingers['f'] = {false, true, true, true, false, false, true, false, false, false};
    fingers['g'] = {false, true, true, true, false, false, false, false, false, false};
    fingers['a'] = {false, true, true, false, false, false, false, false, false, false};
    fingers['b'] = {false, true, false, false, false, false, false, false, false, false};
    fingers['C'] = {false, false, true, false, false, false, false, false, false, false};
    fingers['D'] = {true, true, true, true, false, false, true, true, true, false};
    fingers['E'] = {true, true, true, true, false, false, true, true, false, false};
    fingers['F'] = {true, true, true, true, false, false, true, false, false, false};
    fingers['G'] = {true, true, true, true, false, false, false, false, false, false};
    fingers['A'] = {true, true, true, false, false, false, false, false, false, false};
    fingers['B'] = {true, true, false, false, false, false, false, false, false, false};
    fingers[' '] = {false, false, false, false, false, false, false, false};
    
    cin >> cases;
    cin.ignore();
    for(i = 0; i < cases; i++)
    {
        moves = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        lastFingers = {false, false, false, false, false, false, false, false, false, false};
        getline(cin, song);
        for(auto note : song)
        {
            for(j = 0; j < 10; j++)
            {
                if(fingers[note][j] && !lastFingers[j])
                {
                    moves[j]++;
                }
                lastFingers[j] = fingers[note][j];    
            }
        }
        for(auto element : moves)
        {
            cout << element << " ";
        }
        cout << "\n";
    }    
    
    return 0;
}


