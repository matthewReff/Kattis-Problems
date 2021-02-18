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
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, int> decode;

    // obvious
    decode['0'] = 0;
    decode['1'] = 1;
    decode['2'] = 2;
    decode['3'] = 3;
    decode['4'] = 4;
    decode['5'] = 5;
    decode['6'] = 6;
    decode['7'] = 7;
    decode['8'] = 8;
    decode['9'] = 9;
    decode['A'] = 10;
    decode['C'] = 11;
    decode['D'] = 12;
    decode['E'] = 13;
    decode['F'] = 14;
    decode['H'] = 15;
    decode['J'] = 16;
    decode['K'] = 17;
    decode['L'] = 18;
    decode['M'] = 19;
    decode['N'] = 20;
    decode['P'] = 21;
    decode['R'] = 22;
    decode['T'] = 23;
    decode['V'] = 24;
    decode['W'] = 25;
    decode['X'] = 26;

    // confused digits
    decode['B'] = 8;
    decode['G'] = decode['C'];
    decode['I'] = 1;
    decode['O'] = 0;
    decode['Q'] = 0;
    decode['S'] = 5;
    decode['U'] = decode['V'];
    decode['Y'] = decode['V'];
    decode['Z'] = 2;


    ll cases;
    ll currentCase;
    string inString;
    cin >> cases;

	vector<int> coefficients = {2, 4, 5, 7, 8, 10, 11, 13};

    for(int i = 0; i < cases; i++)
    {
    	cin >> currentCase >> inString;
    	long total = 0;
    	for(int j = 0; j < coefficients.size(); j++)
    	{
    		total += coefficients[j] * decode[inString[j]];
    		total %= 27;
    	}
    	cout << currentCase << " ";
    	if(decode[inString.back()] == total)
    	{
    		total = 0;
    		for(int j = 0; j < 8; j++)
    		{
    			total += pow(27, 7-j) * decode[inString[j]];
    		}
    		cout << total << "\n";
    	}
    	else
    	{
    		cout << "Invalid\n";
    	}
    }

    return 0;
}
