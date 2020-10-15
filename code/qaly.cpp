#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i, j, k;
    int n;
    double num1, num2;
    double tot = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
	cin >> num1 >> num2;
	tot += num1 * num2;
    }

    cout << fixed << setprecision(5);
    cout << tot << "\n";
    return 0;
}
