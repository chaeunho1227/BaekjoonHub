#include <iostream>
using namespace std;

namespace OX_Quiz {

int calculate(string str){
    int tmp = 0, len, score_weight = 0;
    len = (int)str.length();
    for(int i = 0; i < len; i++){
        if (str[i] == 'O')
            score_weight++;
        else
            score_weight = 0;
        tmp += score_weight;
    }
    return tmp;
}
}

int main(){
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        cout << OX_Quiz::calculate(str) << endl;
    }
}
