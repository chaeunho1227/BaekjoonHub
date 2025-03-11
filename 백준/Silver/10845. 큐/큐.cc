#include <iostream>

using namespace std;


class Node{
    public:
    Node* next_node;
    int data;

    Node(int _data){
        data = _data;
        next_node = nullptr;
    }
};

class MyQueue{
    private:
    Node* head;
    Node* rear;

    public:
        MyQueue(){
            head = nullptr;
            rear = nullptr;
        }

        int empty(){
            if(head == nullptr)
                return 1;
            return 0;
        }

        void push(int _data){
            Node* node = new Node(_data);
            if(head == nullptr){
                head = node;
                rear = node;
            }
            else{
               rear->next_node = node;
               rear = node;
            }
        }

        int pop(){
            if(this->empty())
                return -1;
            
            int result = head->data;
            if(head == rear){
                delete head;
                head = nullptr;
                rear = nullptr;
            }else{
                Node* n_node = head->next_node;
                delete head;
                head = n_node;
            }
            return result;
        }

        int size(){
            int result = 0;
            Node* start_node = head;
            while(start_node != nullptr){
                start_node = start_node->next_node;
                result++;
            }
            return result;
        }

        int front(){
            if(this->empty())
                return -1;
            return head->data;
        }

        int back(){
            if(this->empty())
                return -1;

            return rear->data;
        }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    MyQueue Q;
    int count, tmp;
    cin >> count;

    string mstr;
    while(count--){
        cin >> mstr;
        if(mstr == "push"){
            cin >> tmp;
            Q.push(tmp);
        }
        else if (mstr == "pop"){
            cout << Q.pop() << "\n";
        }
        else if (mstr == "front"){
            cout << Q.front() << "\n";
        }
        else if (mstr == "back"){
            cout << Q.back() << "\n";
        }
        else if (mstr == "size"){
            cout << Q.size() << "\n";
        }
        else if (mstr == "empty"){
            cout << Q.empty() << "\n";
        }
    }

    return 0;
}