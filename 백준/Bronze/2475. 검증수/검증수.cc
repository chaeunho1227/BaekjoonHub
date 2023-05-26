#include <iostream>


inline int SQUARE(int x){
    return x*x;
}


int main(){
    using namespace std;
    int arr[5],verify_num = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        verify_num += SQUARE(arr[i]);
    }
    cout << verify_num % 10;
    return 0;
}
