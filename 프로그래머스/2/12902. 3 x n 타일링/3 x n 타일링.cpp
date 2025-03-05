#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1000000007;

int func(int n,unordered_map<int, int> &dp){
    if(n == 2) return dp[2];
    if(n == 4) return dp[4];
    
    if(dp.find(n) == dp.end()){
        dp[n] = (4LL * func(n-2, dp) % MOD - func(n-4, dp) % MOD + MOD) % MOD;
    }
    return dp[n];

}

int solution(int n) {
    int answer = 0;
    if(!(n%2)){
        unordered_map<int, int> dp;
        dp[2] = 3;
        dp[4] = 11;
        
        answer = func(n, dp);
    }
    return answer;
}
