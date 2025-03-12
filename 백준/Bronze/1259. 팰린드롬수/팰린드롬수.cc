#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    string input;

    while(true){
        cin >> input;
        if("0" == input)
            break;
        int size = input.size();
        int mid_index = size / 2;
        bool is_available = true;
        for(int i = 0; i < mid_index; i++){
            if(input[i] != input[size - 1 - i])
                is_available = false;
        }
        if(is_available)
            cout << "yes\n";
        else
            cout << "no\n"; 
    }


    return 0;
}