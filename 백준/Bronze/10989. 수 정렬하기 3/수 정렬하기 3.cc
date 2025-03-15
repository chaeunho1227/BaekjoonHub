#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    short tmp;
    int numbers[10001]={0,};
    
    
    memset(numbers, 0, sizeof(numbers));

    cin >> N;
    while(N--){
        cin >> tmp;
        numbers[tmp]++;
    }
    for(int i = 1; i < 10001; i++){
        while (numbers[i])
        {
            cout << i << "\n";
            numbers[i]--;
        }
    }
    return 0;
}