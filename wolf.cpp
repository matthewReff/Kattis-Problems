#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int cards;
	int value;
	char suit;
	vector<int> c;
	vector<int> s;
	vector<int> h;
	vector<int> d;
	cin >> cards;
	if (cards < 26) {
		cout << "impossible";
	}
	else if(cards > 26){
		cout << "possible";
	}
	else{
		for (int i = 0; i < 26; i++) {
			cin >> value >> suit;
			if (suit == 'C') {
				c.push_back(value);
			}
			if (suit == 'S') {
				s.push_back(value);
			}
			if (suit == 'H') {
				h.push_back(value);
			}
			if (suit == 'D') {
				d.push_back(value);
			}
		}
		for (int i = 0; i < c.size(); i++) {
			if (c[i] != i + 1) {
				cout << "possible";
				return 0;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != i + 1) {
				cout << "possible";
				return 0;
			}
		}
		for (int i = 0; i < h.size(); i++) {
			if (h[i] != i + 1) {
				cout << "possible";
				return 0;
			}
		}
		for (int i = 0; i < d.size(); i++) {
			if (d[i] != i + 1) {
				cout << "possible";
				return 0;
			}
		}
		cout << "impossible";
	}
	return 0;
}
