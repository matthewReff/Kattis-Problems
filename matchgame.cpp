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

int countSetBits(int n) 
{ 
    int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
  

int main()
{
    ll i, j, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, int> digits;
    digits['0'] = 0b1111110;
    digits['1'] = 0b1100000;
    digits['2'] = 0b1011011;
    digits['3'] = 0b1110011;
    digits['4'] = 0b1100101;
    digits['5'] = 0b0110111;
    digits['6'] = 0b0111111;
    digits['7'] = 0b1100010;
    digits['8'] = 0b1111111;
    digits['9'] = 0b1110111;

	/*
    for(char thing = '0'; thing <= '9'; thing++)
    {
    	 for(char thing2 = thing+1; thing2 <= '9'; thing2++)
    	 {
	    	char left = thing;
	    	char right = thing2;
	    	ll diffNum = digits[left] ^ digits[right];
	    	diffNum = countSetBits(diffNum);
	    	if(diffNum <= 2 && abs(countSetBits(digits[left]) - countSetBits(digits[right])) <= 1)
	    	{
	    		cout << thing << " " << thing2 << "\n";
	    	}
    	 }
    }
	*/
    string num1, num2;
    cin >> num1 >> num2;
    ll total = 0;
    for(i = 0; i < (int)num1.size(); i++)
    {
    	char left, right;
    	left = num1[i];
    	right = num2[i];
    	ll diffNum = digits[left] ^ digits[right];
    	if(abs(countSetBits(digits[left]) - countSetBits(digits[right])) <= 1)
    	{
    		total += countSetBits(diffNum);
    	}
    }

    if(total == 2)
    {
    	cout <<"yes\n";
    }
    else
    {
    	cout <<"no\n";
    }
    return 0;
}
