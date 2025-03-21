#include <iostream>

using namespace std;


// Func.h

int Factorial(int n);
int BinoCoefWithFactorial(int n, int k);
// Func.cpp 추가하기


int Factorial(int n){
    // n is always positive.
    if(n <= 1)
        return 1;
    
    int answer = 1;
    for (int i = 2; i <= n; i++)
    {   
        answer *= i;
    }
    return answer;
}

int BinoCoefWithFactorial(int n, int k){
    return Factorial(n) / (Factorial(n-k) * Factorial(k));
}

// func

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n , k;
    cin >> n >> k;
    cout << BinoCoefWithFactorial(n ,k);
    return 0;
}
