#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <ctype.h>

using namespace std;


int main()
{
	long long i, j, k;

	int longest = 0;
	int raggedScore = 0;
	string sentence;
	vector<string> paragraph;
	
	while (getline(cin, sentence) && sentence != "")
	{
		paragraph.push_back(sentence);
		if (sentence.size() > longest)
		{
			longest = sentence.size();
		}
	}

	for (i = 0; i < paragraph.size() - 1; i++)
	{
		raggedScore += pow(longest - paragraph[i].size(), 2);
	}
	cout << raggedScore;
	return 0;
}