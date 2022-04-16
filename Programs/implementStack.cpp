#include<iostream>
#define SIZE 5
using namespace std;

class Stack{
    int index = -1;
    int members[SIZE];
    bool isFull(){
        return(index + 1 == SIZE);
    }
public:
    void push(int n){
        if(isFull()){
            cout << "fullStackException" << endl;
        }
        else{
            members[++index] = n;
        }
    }
    int pop(){
        if(isEmpty()){
            cout << "emptyStackException" << endl;
        }
        else{
            int x = members[index--];
            return x;
        }
    }
    int size(){
        return (index + 1);
    }
    int top(){
        if(isEmpty()){
            cout << "noSuchElementException" << endl;
        }
        else{
            return members[index];
        }
    }
    bool isEmpty(){
        return (index == -1);
    }
};

int main(){
    Stack n;
    n.push(10);
    n.push(20);
    n.push(30);
    n.push(40);
    n.push(50);
    cout << "Top: " << n.top() << endl;
    while(!n.isEmpty()){
        cout << n.pop() << endl;
    }
    return 0;
}
