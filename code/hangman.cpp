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
#include <unordered_set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ll i, j, k;
    
    bool won = false;
    string guessedWord;
    string guessLetters;
    
    cin >> guessedWord;
    cin >> guessLetters;
    
    ll failures = 0;
    ll remainingLetters = guessedWord.length();
    size_t found;
    
    i = 0;
    while(failures < 10 && !won)
    {
    	found = guessedWord.find(guessLetters[i]);
    	if(found != string::npos)
    	{
    		while(found != string::npos)
    		{
    		
    			remainingLetters--;
    			found = guessedWord.find(guessLetters[i], found+1);
    		}
    		if(remainingLetters == 0)
    		{
    			won = true;
    		}	
    	}
    	else
    	{
    		failures++;
    	}
    	i++;
    }
    
 	if(won)
 	{
 		cout << "WIN";
 	}
 	else
 	{
 		cout << "LOSE";  
 	}
    return 0;
}
