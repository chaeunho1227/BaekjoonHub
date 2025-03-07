#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> convertCntVector(string S){
    vector<int> result(10, 0);
    int idx;
    for(char c : S){
        idx = static_cast<int>(c - '0') ;
        result[idx]++;
    }
    return result;
}

string solution(string X, string Y) {
    string answer = "";
    vector<int> num_X = convertCntVector(X);
    vector<int> num_Y = convertCntVector(Y);
    int cnt_num_i;
    for(int i = 9; i >= 0; i--){
        cnt_num_i = (num_X[i] < num_Y[i] ? num_X[i] : num_Y[i]);
        for(; cnt_num_i > 0; cnt_num_i--){
            answer.push_back(static_cast<char>(i) + '0');
        }
    }
    if(answer.empty())
        answer = "-1";
    cout << answer.front() << answer.size();
    while(answer.front() == '0' && answer.size() > 1){
        answer.erase(0,1);
    }
    return answer;
}