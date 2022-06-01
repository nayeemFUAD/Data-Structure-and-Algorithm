#include<iostream>
#define SIZE 5
using namespace std;

class UStack{
    int index = 0, members[SIZE];
    bool isFull(){
        return(index == SIZE);
    }
public:
    void push(int n){
        if(isFull()){
            cout << "fullStackException" << endl;
        }
        else{
            members[index++] = n;
        }
    }
    int pop(){
        if(isEmpty()){
            cout << "emptyStackException" << endl;
        }
        else{
            int x = members[--index];
            return x;
        }
    }
    int size(){
        return index;
    }
    int top(){
        if(isEmpty()){
            cout << "noSuchElementException" << endl;
        }
        else{
            return members[index - 1];
        }
    }
    bool isEmpty(){
        return (index == 0);
    }
};

int main(){
    UStack n;
    n.push(10);
    n.push(20);
    n.push(30);
    n.push(40);
    n.push(50);
    cout << "Size: " << n.size() << endl;
    cout << "Top: " << n.top() << endl;
    while(!n.isEmpty()){
        cout << n.pop() << "\t";
    }
    return 0;
}
