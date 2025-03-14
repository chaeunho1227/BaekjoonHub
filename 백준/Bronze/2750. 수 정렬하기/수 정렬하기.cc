#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &numbers);
void swap(int * a, int * b);

int main(){
    int N, tmp;
    vector<int> numbers;
    cin >> N;
    while(N--){
        cin >> tmp;
        numbers.push_back(tmp);
    }
    sort(numbers);
    for(int i : numbers){
        cout << i << "\n";
    }
    return 0;
}


void sort(vector<int> &numbers){
    int size = numbers.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(numbers[i] > numbers[j])
                swap(&numbers[i], &numbers[j]);
        }
        
    }
    return;
}

void swap(int * a, int * b){
    int tmp = *b;
    *b = * a;
    *a = tmp;
}