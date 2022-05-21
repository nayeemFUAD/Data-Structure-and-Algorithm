#include<iostream>
#define SIZE 5
using namespace std;

class UStack{
    int index = -1;
    int members[SIZE];
    bool isFull(){
        return(index == SIZE - 1);
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
            int x = members[index];
            members[index--] = NULL;
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
            if(isEmpty()){
                cout << "emptyStackException" << endl;
            }
            return members[index];
        }
    }
    bool isEmpty(){
        return (index == -1);
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
