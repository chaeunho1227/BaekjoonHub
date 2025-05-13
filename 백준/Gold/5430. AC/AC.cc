#include <iostream>
#include <deque>
#include <string>

using namespace std;


// Func.h
class ACLanguage{
    private:
        deque<int> arr;
        string command_arr;

    public:
        ACLanguage() : arr() {}

        void SetCommand(const string& input){
            command_arr = RemoveConsecutiveR(input);
        }

        void SetArr(const string& input){
            arr = ConvertStringToDequeInt(input);
        }

        deque<int> ConvertStringToDequeInt(const string& str){
            int size = str.size();
            string str_num = "";
            deque<int> result;

            for (size_t i = 1; i < size - 1; ++i) { // 첫 번째와 마지막 문자 제외
                if (str[i] == ',' || str[i] == ']') {
                    if (!str_num.empty()) { // str_num이 비어 있지 않으면 변환
                        result.push_back(stoi(str_num));
                        str_num.clear();
                    }
                } else {
                    str_num.push_back(str[i]);
                }
            }

            // 루프 종료 후 남아 있는 숫자 처리
            if (!str_num.empty()) {
                result.push_back(stoi(str_num));
            }

            return result;
        }

        string RemoveConsecutiveR(const string& input){
            string result;
            for(char c : input){
                if(!result.empty() && (c == 'R' && result.back() == c)){
                    result.pop_back();
                }else{
                    result.push_back(c);
                }
            }
            return result;
        }

        void ExcuteCommand(){
            bool is_forward = true;
            for(char c : command_arr){
                if(c == 'D'){
                    if(arr.empty()){
                        cout << "error\n";
                        return;
                    }

                    if(is_forward){
                        arr.pop_front();
                    }else{
                        arr.pop_back();
                    }
                } else if (c == 'R')
                    is_forward = !is_forward;
            }
            PrintResult(is_forward);
        }

        void PrintResult(bool is_forward) {
            cout << "[";
            int size = arr.size();
            if (is_forward) {
                for (int i = 0; i < size; ++i) {
                    cout << arr[i];
                    if (i != size - 1) {
                        cout << ",";
                    }
                }
            } else {
                for (int i = size - 1; i >= 0; --i) {
                    cout << arr[i];
                    if (i != 0) {
                        cout << ",";
                    }
                }
            }
            cout << "]\n";
        }
};

// Func.cpp 추가하기

// func


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int testcnt, size;
    string command, arr;

    cin >> testcnt;
    ACLanguage* ac = nullptr;
    while (testcnt--){
        cin >> command >> size >> arr;
        ac = new ACLanguage;
        ac->SetArr(arr);
        ac->SetCommand(command);
        ac->ExcuteCommand();
        delete ac;
    }
    return 0;
}
