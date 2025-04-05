#include <iostream>
#include <vector>

using namespace std;

class Sort{
    public:
        void swap(vector<pair<int,int>> &v, int a, int b);
        void mergesort(vector<pair<int,int>> &v);
        void mergesort(vector<pair<int,int>> &v, int start, int end);
        void merge(vector<pair<int,int>> &v, int start, int mid, int end);
};

void Sort::swap(vector<pair<int,int>> &v, int a, int b){
    pair<int,int> tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
};

void Sort::mergesort(vector<pair<int,int>> &v){
    int start = 0;
    int end = v.size() - 1;
    if(start < end){
        int mid = (end + start) / 2;
        mergesort(v, start, mid);
        mergesort(v, mid + 1, end);

        merge(v, start, mid, end);
    }
};

void Sort::mergesort(vector<pair<int,int>> &v, int start, int end){
    if(start < end){
        int mid = (end + start) / 2;
        mergesort(v, start, mid);
        mergesort(v, mid + 1, end);
        
        merge(v, start, mid, end);
    }
};

void Sort::merge(vector<pair<int,int>> &v, int start, int mid, int end){
    vector<pair<int,int>> tmp_v;

    int first_vec_idx = start, second_vec_idx = mid + 1;

    while (first_vec_idx <= mid && second_vec_idx <= end){
        if (v[first_vec_idx].second < v[second_vec_idx].second || 
            (v[first_vec_idx].second == v[second_vec_idx].second && v[first_vec_idx].first < v[second_vec_idx].first)) {
            tmp_v.push_back(v[first_vec_idx++]);
        } else {
            tmp_v.push_back(v[second_vec_idx++]);
        }
    }
    
    while (first_vec_idx <= mid){
        tmp_v.push_back(v[first_vec_idx++]);
    }
    
    int v_idx = start;
    for(auto element : tmp_v){
        v[v_idx++] = element;
    }
};

int solution(vector<pair<int,int>> meetings){
    Sort s;
    s.mergesort(meetings);
    int prev_end = 0, avilable_count = 0;
    for (auto meeting : meetings)
    {
        if(meeting.first >= prev_end){
            avilable_count++;
            prev_end = meeting.second;
        }
    }
    
    return avilable_count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int count;
    cin >> count;
    vector<pair<int,int>> meetings;

    int start, end;
    while (count--)
    {
        cin >> start >> end;
        meetings.push_back(make_pair(start, end));
    }
    
    int answer = solution(meetings);
    cout << answer;
    return 0;
}
