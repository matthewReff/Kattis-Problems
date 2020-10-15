#include <iostream>
#include <string>
using namespace std;

int main(){
    string hiss;
    cin >> hiss;
    for(int i = 0; i < hiss.length()-1; i++){
        if(hiss.at(i) == 's' && hiss.at(i+1) == 's'){
            cout << "hiss";
            return 0;
        }
    }
    cout << "no hiss";
    return 0;
}