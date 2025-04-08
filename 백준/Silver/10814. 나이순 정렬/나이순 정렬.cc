#include <iostream>
#include <vector>
#include <string>
// BOJ 제출시 main.cpp로 복사.

using namespace std;

class Member{
    public:
        int age;
        string name;

        Member() : age(0), name("") {}
        Member(int _age, string _name);
};

class MemberManager{
    private:
        vector<Member> members;
    public:
        void AddMember(int _age, string _name);
        void AddMember(const Member& member);
        void SortMembers();
        void PrintMembers();
};

class MemberPrinter{
    public:
        static void PrintMembers(const vector<Member>& members);
};

class MemberSorter{
    public:
        static void MergeSort(vector<Member>& members);
    private:
        static void MergeSortHelper(vector<Member>& members, int left, int right);
        static void Merge(vector<Member>& members, int left, int mid, int right);
};

Member::Member(int _age, string _name){
    age = _age;
    name = _name;
}

void MemberManager::AddMember(int _age, string _name){
    Member member(_age, _name);
    AddMember(member);
}

void MemberManager::AddMember(const Member& member){
    members.push_back(member);
};

void MemberManager::SortMembers(){
    MemberSorter::MergeSort(members);
}

void MemberManager::PrintMembers(){
    MemberPrinter::PrintMembers(members);
}

void MemberSorter::MergeSort(vector<Member>& members){
    MergeSortHelper(members, 0, members.size() - 1);
};

void MemberSorter::MergeSortHelper(vector<Member>& members, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSortHelper(members, left, mid);
        MergeSortHelper(members, mid+1, right);
        Merge(members, left, mid, right);
    }
};

void MemberSorter::Merge(vector<Member>& members, int left, int mid, int right){

    int size = right - left + 1;

    vector<Member> temp(size);
    int i = left, j = mid + 1, temp_index = 0;

    while (i <= mid && j <= right){
        if(members[i].age <= members[j].age){
            temp[temp_index++] = members[i++];
        }else{
            temp[temp_index++] = members[j++];
        }
    }

    while(i <= mid) temp[temp_index++] = members[i++];
    while(j <= right) temp[temp_index++] = members[j++];

    for (int l = 0; l < size; l++)
    {
        members[left + l] = temp[l];
    }
};

void MemberPrinter::PrintMembers(const vector<Member>& members){
    for(Member member : members){
        cout << member.age << " " << member.name << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    MemberManager manager;

    int count;
    cin >> count;

    int age;
    string name;
    while(count--){
        cin >> age >> name;
        manager.AddMember(age,name);
    }
    manager.SortMembers();
    manager.PrintMembers();

    return 0;
}
