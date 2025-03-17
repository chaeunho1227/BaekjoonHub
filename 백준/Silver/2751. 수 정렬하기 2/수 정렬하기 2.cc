#include <iostream>

using namespace std;

// Func.h
#include <vector>

namespace MyFunc {
    class MyMergeSort{
        public:
            static void MergeSort(vector<int> &v);
        private:
            static void MergeSort(vector<int> &v, int start, int end);
            static void Merge(vector<int> &v, int start, int end);
    };
}

// Func.cpp 추가하기

namespace MyFunc{
    void MyMergeSort::MergeSort(vector<int> &v){
        int end = v.size() - 1;
        MergeSort(v, 0, end);
    }

    void MyMergeSort::MergeSort(vector<int> &v, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            MergeSort(v, start, mid);
            MergeSort(v, mid+1, end);

            Merge(v, start, end);
        }
    }

    void MyMergeSort::Merge(vector<int> &v, int start, int end){
        vector<int> sorted_v;

        // Merge
        int mid = (start + end) / 2;
        int i = start, j = mid + 1;
        while(i <= mid && j <= end){
            if(v[i] < v[j])
                sorted_v.push_back(v[i++]);
            else
                sorted_v.push_back(v[j++]);
        }

        // add remains to sorted_v 
        while(i <= mid){
            sorted_v.push_back(v[i++]);
        }

        // copy sorted_v to v
        int size_of_sorted_v = sorted_v.size();
        for (int i = 0; i < size_of_sorted_v; i++)
        {   
            v[i+start] = sorted_v[i];
        }
        
    }
}
// func

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int N, tmp;
    cin >> N;

    vector<int> v;
    while(N--){
        cin >> tmp;
        v.push_back(tmp);
    }

    MyFunc::MyMergeSort::MergeSort(v);

    for(int i : v){
        cout << i << '\n';
    }
    return 0;
}
