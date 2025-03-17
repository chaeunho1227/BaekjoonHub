#include <iostream>

using namespace std;
// Func.h
#include <cmath>
#include <vector>

// Func.cpp 추가하기


int GetN(int N, int r, int c){
    if(0 == N)
        return 0;

    int mid = pow(2,N) / 2;

    int weight;


    if(r >= mid){
        if(c >= mid) {
            // IV 사분면 3
            weight = 3;
            c = c-mid;
        }
        else {
            // III 사분면 2
            weight = 2;
        }
        r = r-mid;
    }
    else{
        if(c >= mid) {
            // I 사분면 / r 유지
            weight = 1;
            c = c-mid;
        }
        else {
            // II 사분면 0 / r,c 유지
            weight = 0;
        }
    }

    return weight * pow(2,2*(N-1)) + GetN(N-1, r, c);
}

// func




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, r, c;
    cin >> N >> r >> c;
    cout << GetN(N, r, c);
    return 0;
}
