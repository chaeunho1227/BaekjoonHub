#include <iostream>

using namespace std;


// Func.h

// Func.cpp 추가하기

// func

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a_1, a_0, c, n;
    cin >> a_1 >> a_0 >> c >> n;
    int answer = 0;
    if(a_1 >= c){
        if(a_1 * 100 + a_0 <= c * 100)
            answer = 1;
    }else{
        if(a_1 * n + a_0 <= c * n)
            answer = 1;
    }
    cout << answer;
    return 0;
}
