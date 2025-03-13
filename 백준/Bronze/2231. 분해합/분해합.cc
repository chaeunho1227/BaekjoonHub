#include <iostream>
#include <vector>

using namespace std;

int getDigitCnt(int N);
int getDivisionSum(int N);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    
    int digit_cnt = getDigitCnt(N);

    int start_num = N - 9 * digit_cnt;
    int answer = 0;
    for (int i = start_num; i < N; i++){
        if(N == getDivisionSum(i)){
            answer = i;
            break;
        }
    }

    cout << answer;
    return 0;
}

int getDigitCnt(int N){
    int digit_cnt = 1;
    while(N /= 10){
        digit_cnt++;
    }
    return digit_cnt;
};

int getDivisionSum(int N){
    int result = N;
    while(N){
        result += N % 10;
        N /= 10;
    }
    return result;
}