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
    /*
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    */
    ll i, j, k;
    ll tempI, tempJ;
    
    ll rows, cols;
    ll top;
    cin >> rows >> cols;
    vector<string> board(rows);
    vector<set<int>> adj(rows * cols);
    vector<vector<bool>> seen(rows);
    vector<vector<ll>> distance(rows);
    queue<int> q;
    for(i = 0; i < rows; i++)
    {
        cin >> board[i];
        seen[i].resize(cols, false);
        distance[i].resize(cols, -1);
    }
    
    //construct adjacency
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            for(k = 0; k < 4; k++)
            {
                switch(k)
                {
                    case 0:
                        tempI = i;
                        tempJ = j + (board[i][j] - '0');
                        break;
                    case 1:
                        tempI = i + (board[i][j] - '0');
                        tempJ = j;
                        break;
                    case 2:
                        tempI = i;
                        tempJ = j - (board[i][j] -'0');
                        break;
                    case 3:
                        tempI = i - (board[i][j] - '0');
                        tempJ = j;
                        break;
                };
                
                if (tempJ >= 0 && tempJ < cols && tempI >= 0 && tempI < rows && (tempJ != j || tempI != i))
                {
                    //cout << "tempI: " << tempI << " tempJ: " << tempJ << "\n"; 
                    //cout << ((tempI * cols) + tempJ) << " " << ((i * cols) +j) << "\n";
                    //adj[(tempI * cols) + tempJ].insert((i * cols) + j);
                    adj[(i * cols) +j].insert((tempI * cols) + tempJ);
                }
            }
        }
    }
    
    /*
    ll trackNum = 0;
    for(auto thing : adj)
    {
        cout << trackNum << ": ";
        for(auto entry : thing)
        {
            cout << entry << " ";
        }
        cout << "\n";
        trackNum++;
    }
    */
    
    q.push(0);
    seen[0][0] = true;
    distance[0][0] = 0;
    while(q.size())
    {
        top = q.front();
        q.pop();
        for(auto entry : adj[top])
        {
            if(!seen[entry / cols][entry % cols])
            {
                seen[entry / cols][entry % cols] = true;
                //cout << "going from: " << top / cols << " " << top % cols << " to ";
                //cout << entry / cols << " " << entry % cols << " with dist " << distance[top / cols][top % cols]+ 1 << "\n";
                distance[entry / cols][entry % cols] = distance[top / cols][top % cols] + 1;
                q.push(entry);
            }
        }
    }
    
    cout << distance[rows-1][cols-1] << "\n";
    
    return 0;
}
