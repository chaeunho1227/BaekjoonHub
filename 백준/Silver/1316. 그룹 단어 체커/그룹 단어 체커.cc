#include <iostream>

using namespace std;

namespace Group {
bool used_alphabet[26];

int len;

void set_false_bool_array_(bool array[],int size){
    for(int i = 0; i < size; i++)
        array[i] = false;
    return;
}

bool check_groupword(string words){
    bool is_group = true;
    set_false_bool_array_(used_alphabet, 26);
    len = (int)words.length();
    
    for(int i = 0; i < len; i++){
        if(used_alphabet[(int)words[i]-97] == false){
            used_alphabet[(int)words[i]-97] = true;
            while (words[i] == words[i+1]) {
                i++;
            }
        }
        else{
            is_group = false;
            break;
        }
    }
    return is_group;
}

}

int main(){
    using namespace Group;
    int N,cnt = 0;
    string words;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> words;
        if(check_groupword(words))
            cnt++;
    }
    cout << cnt;
}
