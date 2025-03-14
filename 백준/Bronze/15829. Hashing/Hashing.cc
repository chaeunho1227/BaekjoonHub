#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1234567891;
const int R = 31;

long long hashingString(string str, int digits_cnt);
int convertAlphabetToInt(char c);

int main(){

    int digits_cnt;
    string str;

    cin >> digits_cnt >> str;

    long long answer = hashingString(str, digits_cnt);
    cout << answer;
    return 0;
}


long long hashingString(string str, int digits_cnt){
    long long base = 1;
    long long result = 0;
    char c;
    for (int i = 0; i < digits_cnt; i++)
    {
        c = str[i];
        result += (base * convertAlphabetToInt(c)) % MOD;
        base = (base * R) % MOD;

    }
    result %= MOD;
    return result;
};

int convertAlphabetToInt(char c){
    return static_cast<int>(c) - 'a' + 1;
};