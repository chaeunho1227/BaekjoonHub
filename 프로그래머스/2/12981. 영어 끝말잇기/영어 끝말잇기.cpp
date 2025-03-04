#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int wrong_idx = 0;
    int words_size = words.size();
    for(int i = 1; i < words_size ; i++){
        if(words[i-1].back() != words[i][0]){
            wrong_idx = i;
            cout << "\nworng_01 " << words[i];
            break;
        }
        if(find(words.begin(), words.begin() + i, words[i]) != words.begin() + i){
            wrong_idx = i;
            cout << "\nworng_02 " << words[i];
            break;

        }
        cout << "\npass";
    }
    
    if(wrong_idx == 0){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    cout << wrong_idx;
    answer.push_back(wrong_idx % n + 1);
    answer.push_back(wrong_idx/n + 1);
    
    return answer;
}