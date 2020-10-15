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
    ll bound;
    ll islands = 0;
    ll garb;
    ll cases;
    ll temp, temp2;
    ll left, right;
    cin >> cases;
    
    for(i = 0; i < cases; i++)
    {
        vector<ll> sequence (12);
        islands = 0;
        cin >> garb;
        for(j = 0; j < 12; j++)
        {
            cin >> sequence[j];
        }
        
        for(j = 1; j < 11; j++)
        {
            for(k = 10; k >= 0; k--)
            {
                if ((j + k) < 11)
                {
                    temp = *(max_element(sequence.begin()+j, sequence.begin() + j + k + 1));
                    temp2 = *(min_element(sequence.begin()+j, sequence.begin() + j + k + 1));
                    left = sequence[j-1];
                    right = sequence[j + k + 1];  
                    if (temp > left && temp > right && temp2 > left && temp2 > right )
                    {
                        islands++;
                        //cout << "range: " << j << "->" << j + k << " " << temp << " " << temp2 << "\n";
                        //cout << "left: " << left << " " << "right: " << right << "\n";
                    }
                }            
            }
        }
        cout << garb << " " << islands << "\n";
    }
    
   
    
    return 0;
}
