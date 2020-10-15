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
    
    string line;
    string hex;
    char xType;
    while(getline(cin, line) && cin)
    {
        if(line != "")
        {
            for(i = 0; i < line.size() - 1; i++)
            {
                if(line[i] == '0' && (line[i + 1] == 'x' || line[i+1] == 'X'))
                {
                    if(line[i+1] == 'x')
                    {
                        xType = 'x';
                    }
                    else
                    {
                        xType = 'X';
                    }
                    
                    hex = "";
                    j = i + 2;
                    while(j < line.size() && isxdigit(line[j]))
                    {
                        hex += line[j];
                        j++;
                    }
                    if(hex != "")
                    {
                        cout << "0" << xType << hex << " " << stoull(hex, nullptr, 16) << "\n";
                    }
                }
            }
        }
    }
        
    return 0;
}
