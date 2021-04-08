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

 int lcs(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1]; 
    int i, j; 
      
    /* Following steps build L[m+1][n+1] in 
       bottom up fashion. Note that L[i][j] 
       contains length of LCS of X[0..i-1]
       and Y[0..j-1] */
    for (i = 0; i <= m; i++) 
    { 
        for (j = 0; j <= n; j++) 
        { 
        if (i == 0 || j == 0) 
            L[i][j] = 0; 
      
        else if (X[i - 1] == Y[j - 1]) 
            L[i][j] = L[i - 1][j - 1] + 1; 
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
          
    /* L[m][n] contains length of LCS 
    for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

int main()
{
    ll i, j, k;
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    string inputString;
    string alphabetString = "abcdefghijklmnopqrstuvwxyz";

    cin >> inputString;
    int longest = lcs(inputString, alphabetString, inputString.size(), alphabetString.size());
    cout << 26 - longest << "\n";
    return 0;
}
