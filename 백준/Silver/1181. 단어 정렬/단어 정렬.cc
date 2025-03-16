#include <iostream>
// Func.h

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

namespace MyFunc{
    void swap(std::string * a,std::string * b);
    void eraseDuplicatedWord(std::vector<std::string> &strings);
    void mergeSort(std::vector<std::string> &strings);
    void mergeSort(std::vector<std::string> &strings, int start, int end);
    void merge(std::vector<std::string> &strings, int start, int end);
}

// Func.cpp 추가하기

using namespace std;
using namespace MyFunc;

namespace MyFunc {
    void swap(string * a,string * b){
        string tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void eraseDuplicatedWord(std::vector<std::string> &strings){
        for(auto it_i = strings.begin(); it_i != strings.end(); ++it_i){
            for(auto it_j = it_i + 1; it_j != strings.end(); ++it_j){
                if (it_i->compare(*it_j) == 0){
                    strings.erase(it_j);
                    it_j--;
                }
            }
        }
    };

    void mergeSort(std::vector<std::string> &strings){
        int start = 0;
        int end = strings.size() - 1;
        int mid = (end + start) / 2;

        mergeSort(strings, start, mid);
        mergeSort(strings, mid+1, end);

        merge(strings, start, end);
    }

    void mergeSort(std::vector<std::string> &strings, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            mergeSort(strings, start, mid);
            mergeSort(strings, mid+1, end);
        }
        
        merge(strings, start, end);
    };

    void merge(std::vector<std::string> &strings, int start, int end){
        
        // Size One
        if(start == end)
            return;

        int size = end - start + 1;
        std::vector<std::string> temp(size);
        
        // merge
        int mid = (start + end) / 2;
        int idx = 0;

        int i = start, j = mid + 1;
        while(i <= mid && j <= end){
            
            // 길이 우선 정렬
            if(strings[i].size() < strings[j].size())
                temp[idx] = strings[i++];
            else if(strings[i].size() > strings[j].size())
                temp[idx] = strings[j++];
            else{
                // 사전식 배열
                if(strings[i].compare(strings[j]) < 0)
                    temp[idx] = strings[i++];
                else
                    temp[idx] = strings[j++];
            }
            idx++;
        }

        
        while(idx < size && i <= mid){
            temp[idx] = strings[i++];
            idx++;
        }

        // copy temp to strings
        
        for(i = 0; i < size; i++){
            if (temp[i] != "")
            {
                strings[i + start] = temp[i];
            }
        }
    };

}
// func

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string str;
    vector<string> strings;
    while(n--){
        cin >> str;
        strings.push_back(str);
    }

    mergeSort(strings);
    strings.erase(unique(strings.begin(),strings.end()),strings.end());
    for(auto s : strings){
        cout << s << '\n';
    }
    return 0;
}
