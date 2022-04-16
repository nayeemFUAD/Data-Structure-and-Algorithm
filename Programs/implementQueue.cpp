#include<iostream>
#define SIZE 5
using namespace std;

class Queue{
    int f = -1;
    int r = 0;
    int members[SIZE];
    bool isFull(){
        return (r == SIZE);
    }
public:
    void enqueue(int n){
        if(isFull()){
            cout << "fullQueueException" << endl;
        }
        else{
            if(f == -1){
                f = 0;
            }
            members[++r - 1] = n;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout << "emptyStackException" << endl;
        }
        else{
            int x = members[f];
            for(int i = 0; i < r; i++){
                members[i] = members[i + 1];
            }
            r--;
            return x;
        }
    }
    bool isEmpty(){
        return (r == 0);
    }
    int front(){
        if(isEmpty()){
            cout << "noSuchElementException" << endl;
        }
        else{
            return (members[f]);
        }
    }
    int back(){
        if(isEmpty()){
            cout << "noSuchElementException" << endl;
        }
        else{
            return (members[r - 1]);
        }
    }
    int size(){
        return r;
    }
};


int main(){
    Queue n;
    n.enqueue(10);
    n.enqueue(20);
    n.enqueue(30);
    n.enqueue(40);
    n.enqueue(50);
    n.dequeue();
    n.enqueue(60);
    while(!n.isEmpty()){
        cout << n.dequeue() << endl;
    }
    return 0;
}
