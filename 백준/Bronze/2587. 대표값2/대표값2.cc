#include <iostream>

using namespace std;

const int INPUT_COUNT = 5;
int getAverage(int arr[]);
int getMiddleNum(int arr[]);
void swap(int * a, int * b);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int numbers[INPUT_COUNT];
    
    int count = INPUT_COUNT;
    int tmp;
    while (count--){
        cin >> tmp;
        numbers[count] = tmp;
    }

    cout << getAverage(numbers) << '\n';
    cout << getMiddleNum(numbers) << '\n';

    return 0;
}


int getAverage(int arr[]){
    int sum = 0;
    for (int i = 0; i < INPUT_COUNT; i++)
    {
        sum += arr[i];
    }
    return sum / INPUT_COUNT;    
};


int getMiddleNum(int arr[]){
    for (int i = 0; i < INPUT_COUNT; i++)
    {
        for (int j = i+1; j < INPUT_COUNT; j++)
        {
            if(arr[i] > arr[j])
                swap(&(arr[i]),&(arr[j]));
        }   
    }
    return arr[INPUT_COUNT / 2];
};


void swap(int * a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}