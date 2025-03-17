#include <iostream>

using namespace std;

// Func.h
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

namespace MyFunc{
    class Statistics{
        public:
            int GetArithmeticMean(vector<int> sorted_v) const;
            int GetMedianValue(vector<int> sorted_v) const;
            int GetRange(vector<int> sorted_v) const;
            int GetModeNumber(vector<int> sorted_v) const;


    };
    
    class MergeSortVector{
        public:
            static void MergeSort(vector<int> &v);
        private:
            static void MergeSort(vector<int> &v, int start, int end);
            static void Merge(vector<int> &v, int start, int end);
    };  
}

// Func.cpp 추가하기
namespace MyFunc {
    int Statistics::GetArithmeticMean(vector<int> sorted_v) const {
        int sum = 0;
        for(int i : sorted_v){
            sum += i;
        }
        int result = round(static_cast<double>(sum) / sorted_v.size());
        return static_cast<int>(result);
    }

    int Statistics::GetMedianValue(vector<int> sorted_v) const{
        int mid = sorted_v.size() / 2;
        return sorted_v[mid];
    };
    
    int Statistics::GetRange(vector<int> sorted_v) const{
        int start = 0, end = sorted_v.size() - 1;
        return sorted_v[end] - sorted_v[start];
    };

    int Statistics::GetModeNumber(vector<int> sorted_v) const{
        unordered_map<int, int> freq_map;
        int max_freq = 0;
    

        for (int num : sorted_v) {
            freq_map[num]++;
            max_freq = max(max_freq, freq_map[num]); 
        }
    
        vector<int> mode_candidates;
        for (const auto& [num, freq] : freq_map) {
            if (freq == max_freq) {
                mode_candidates.push_back(num);
            }
        }

        MergeSortVector::MergeSort(mode_candidates);
    
        return (mode_candidates.size() > 1) ? mode_candidates[1] : mode_candidates[0];
    };

    void MergeSortVector::MergeSort(vector<int> &v){
        int size = v.size();
        int start = 0, end = size - 1;
        MergeSort(v,start,end);
    }

    void MergeSortVector::MergeSort(vector<int> &v, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            MergeSort(v, start, mid);
            MergeSort(v, mid + 1, end);
            
            Merge(v, start, end);
        }
    }

    void MergeSortVector::Merge(vector<int> &v, int start, int end){

        vector<int> sorted_v;

        int mid = (start + end) / 2;
        int i = start;
        int j = mid + 1;

        while (i <= mid && j <= end){
            if(v[i] < v[j])
                sorted_v.push_back(v[i++]);
            else
                sorted_v.push_back(v[j++]);
        }
        
        
        while(i <= mid){
            sorted_v.push_back(v[i++]);
        }

        int idx = start;
        for(int sorted_i : sorted_v){
            v[start++] = sorted_i;
        }
    }
}

// func

using namespace MyFunc;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<int> nums;
    while(N--){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    Statistics s;
    MergeSortVector::MergeSort(nums);
    cout << s.GetArithmeticMean(nums) << '\n';
    cout << s.GetMedianValue(nums) << '\n';
    cout << s.GetModeNumber(nums) << '\n';
    cout << s.GetRange(nums) << '\n';
    return 0;
}
