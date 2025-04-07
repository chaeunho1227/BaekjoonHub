#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long input, count , degree = 3;
    cin >> input;
    count = input * (input - 1) * (input - 2) / 6;
    cout << count << endl << degree;
    return 0;
}
