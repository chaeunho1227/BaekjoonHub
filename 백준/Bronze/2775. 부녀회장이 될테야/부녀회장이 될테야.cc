#include <iostream>

using namespace std;

// Func.h
#include <vector>

void update_people_cnt(vector<vector<int>> &people, int k, int n);

// Func.cpp 추가하기

// func

void update_people_cnt(vector<vector<int>> &people, int k, int n){
    if(people[k][n] != 0)
        return;
    for (int floor= 1; floor <= k; floor++){
        if(people[floor][n] != 0)
            continue;
        
        int sum = 0;
        for (int number = 1; number <= n; number++){
            sum += people[floor - 1][number];
            people[floor][number] = sum;
        }
    }
}


int main(){

    const int MAX = 15;
    vector<vector<int>> people(MAX,vector<int>(MAX,0));

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i < MAX; i++){
        people[0][i] = i;
    }

    int testcnt, k , n;
    cin >> testcnt;

    while(testcnt--){
        cin >> k >> n;
        update_people_cnt(people, k , n);
        cout << people[k][n] << '\n';
    }

    return 0;
}
