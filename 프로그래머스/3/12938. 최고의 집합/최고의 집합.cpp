#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {

    if(n > s){
        vector<int> answer1(1, -1);
        return answer1;
    }
    vector<int> answer(n, s/n);
    int mod = s%n;
    cout << mod;
    for(int i = 1; i <= mod ; i++){
        answer[n-i]++;
    }
    return answer;
}