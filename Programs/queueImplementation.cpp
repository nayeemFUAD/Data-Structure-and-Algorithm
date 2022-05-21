
// 1. Implement Queue

#include<iostream>
#define SIZE 5
using namespace std;

class UQueue{
    int members[SIZE], i = -1;
    bool isFull(){
        return(i == SIZE - 1);
    }
public:
    void enqueue(int n){
        if(isFull()){
            cout << "fullQueueException" << endl;
        }
        else{
            members[++i] = n;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout << "emptyQueueException" << endl;
        }
        else{
            int x = members[0];
            for(int j = 0; j < size(); j++){
                members[j] = members[j + 1];
            }
            members[i--] = NULL;
            return x;
        }
    }
    int size(){
        return (i + 1);
    }
    bool isEmpty(){
        return (i == -1);
    }
    int front(){
        if(isEmpty()){
            cout << "emptyQueueException" << endl;
        }
        else{
            return members[0];
        }
    }
};

int main(){
    UQueue u;
    u.enqueue(10);
    u.enqueue(20);
    u.enqueue(30);
    u.enqueue(40);
    u.enqueue(50);
    cout << "Size: " << u.size() << endl;
    cout << "Front: " << u.front() << endl;
    while(!u.isEmpty()){
        cout << u.dequeue() << "\t";
    }
    return 0;
}
