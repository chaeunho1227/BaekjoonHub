#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsFizzBuzz(string s){
    if(s == "FizzBuzz" || s == "Fizz" || s== "Buzz")
        return true;
    return false;
}   

int FindNextFizzBuzz(vector<string> str){
    int i = 3;
    int answer;
    for (string s : str){
        if(!IsFizzBuzz(s)){
            answer = stoi(s) + i;
        }
        i--;
    }
    return answer;
}

void PrintFizzBuzz(int n){
    string answer = "";
    if((n % 3) == 0 && (n % 5) == 0)
        answer.append("FizzBuzz");
    else if((n % 3) == 0)
        answer.append("Fizz");
    else if((n % 5) == 0)
        answer.append("Buzz");
    else{
        cout << n;
        return;
    }
    cout << answer;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<string> str(3);
    cin >> str[0] >> str[1] >> str[2];
    int n = FindNextFizzBuzz(str);
    PrintFizzBuzz(n);
    return 0;
}
