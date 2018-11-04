#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    map < char, int> cards;
    long long i, j, k;
    int max = 0;
    char suit, card;
    for(i = 0; i < 5; i++)
    {
	cin >> card>> suit;
	cards[card]++;
    }   
    map<char, int >::iterator itr;
    itr = cards.begin();
    while(itr != cards.end())
    {
	if ((*itr).second > max)
	{
	    max = (*itr).second;
	}
	itr++;
    
    }
    cout << max << "\n";
    return 0;
}
