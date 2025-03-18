#include <iostream>

using namespace std;


// Func.h
#include <vector>

const int MAX_LEN = 2147483647;

long long GetCount(const vector<int>& v,int length);
int GetMaxLen(const vector<int>& v,int min, int max, int N);

// Func.cpp 추가하기


long long GetCount(const vector<int> &v,long long length){
    long long count = 0;
    for(int i : v){
        count += i / length;
    }
    return count;
};

// func

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, count_lan, tmp;
    cin >> N >> count_lan;

    vector<int> v;
    while(N--){
        cin >> tmp;
        v.push_back(tmp);
    }

    long long low = 1;
    long long high = 0;
    for(int i : v){
        if(high < i)
            high = i;
    }
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (GetCount(v, mid) >= count_lan) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << low - 1;
    return 0;
}
