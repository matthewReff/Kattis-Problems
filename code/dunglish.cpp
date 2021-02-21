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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    ll numWords;
    cin >> numWords;
    ll numTranslations;
    vector<string> words(numWords);
    map<string, vector<string>> correct;
    map<string, vector<string>> incorrect;

    for(int i = 0; i < numWords; i++)
    {
    	cin >> words[i];
    }

    cin >> numTranslations;
    string dutch, english, correctness;
    for(int i = 0; i < numTranslations; i++)
    {
    	cin >> dutch >> english >> correctness;
    	if(correctness == "correct")
    	{
    		correct[dutch].push_back(english);
    	}
    	else
    	{
    		incorrect[dutch].push_back(english);
    	}
    }

    ll totalCorrect = correct[words[0]].size();
    ll totalIncorrect = incorrect[words[0]].size();

    for(int i = 1; i < numWords; i++)
    {
    	ll newCorrect = 0;
    	ll newIncorrect = 0;
    	auto elem = correct.find(words[i]);
    	if(elem != correct.end())
    	{
    		newCorrect = elem->second.size();
    	}
    	elem = incorrect.find(words[i]);
    	if(elem != incorrect.end())
    	{
    		newIncorrect = elem->second.size();
    	}

    	ll oldIncorrect = totalIncorrect;
    	totalIncorrect = (totalCorrect + totalIncorrect) * newIncorrect;
    	totalIncorrect += oldIncorrect * newCorrect;
    	totalCorrect *= newCorrect;
    }

    if(totalCorrect + totalIncorrect == 1)
    {
    	for(int i = 0; i < numWords; i++)
    	{
    		auto found = incorrect.find(words[i]);
    		if(found != incorrect.end())
    		{
    			for(auto elem : incorrect[words[i]])
    			{
    				cout << elem << " ";
    			}
    		}

    		found = correct.find(words[i]);
    		if(found != correct.end())
    		{
    			for(auto elem : correct[words[i]])
    			{
    				cout << elem << " ";
    			}
    		}
    		//else
    		//{
    		//	cout << correct[words[i]][0] << " ";
    		//}
    	}
    	if(totalCorrect == 1)
    	{
    		cout << "\ncorrect\n";
    	}
    	else
    	{
    		cout << "\nincorrect\n";
    	}
    }
    else
    {
    	cout << totalCorrect << " correct\n";
    	cout << totalIncorrect << " incorrect\n";
    }

    return 0;
}
