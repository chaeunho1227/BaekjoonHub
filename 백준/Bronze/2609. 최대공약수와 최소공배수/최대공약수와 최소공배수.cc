#include <iostream>

using namespace std;

int getGCD(int A, int B);
int getLCM(int A, int B);

int main(){
    int A, B;
    cin >> A >> B;

    cout << getGCD(A, B) << "\n" << getLCM(A ,B);

    return 0;
}


int getGCD(int A, int B){
    return A % B ? getGCD(B, A % B) : B;
};


int getLCM(int A, int B){
    int gcd = getGCD(A, B);
    return A * B / gcd;
};
