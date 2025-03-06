#include <string>
#include <vector>
#include <iostream>
using namespace std;

int countSet(vector<int>& cards,int start_idx = 0){
    int next_idx, cnt = 0;
    int& target_idx = start_idx;
    do{
        next_idx = cards[target_idx];
        // cout << target_idx + 1 << " 번째 상자 : " << next_idx << "\n";
        if(next_idx == 0) break;
        next_idx--;
        cards[target_idx] = 0;
        cnt++;
        target_idx = next_idx;
    }while(true);
    return cnt;
}

int solution(vector<int> cards) {
    int answer = 0;
    int first_set_size = 0;
    int second_set_size = 0, temp_size;
    
    int cards_size = cards.size();
    for(int  i = 0;  i < cards_size ; i++){
        if(cards[i] == 0) continue;
        temp_size = countSet(cards, i);
        cout << temp_size << " : ";
        if(temp_size > first_set_size){
            if(first_set_size > second_set_size){
                second_set_size = first_set_size;
            cout << "second 변경->" << second_set_size << " / ";
            }
            first_set_size = temp_size;
            cout << "first 변경 ->" << first_set_size << "\n";
        }
        else if(temp_size > second_set_size){
            second_set_size = temp_size;
            cout << "second 변경->" << second_set_size << "\n";
        }
        cout << "\n";
    }
    cout << first_set_size << " " << second_set_size;
    answer = first_set_size * second_set_size;
    return answer;
}