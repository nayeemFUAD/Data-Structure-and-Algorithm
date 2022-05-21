#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1, q2;
public:
    bool isEmpty(){
        return q1.empty();
    }
    void push(int n){
        q1.push(n);
    }
    int pop(){
        if(q1.empty()){
            cout << "emptyStackException" << endl;
        }
        else{
            int s = q1.size();
            for(int i = 0; i < s - 1; i ++){
                int x = q1.front();
                q2.push(x);
                q1.pop();
            }
            int y = q1.front();
            q1.pop();
            while(!q2.empty()){
                int x = q2.front();
                q1.push(x);
                q2.pop();
            }
            return y;
        }
    }
    int size(){
        return q1.size();
    }
    int top(){
        return q1.back();
    }
};



int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout << "Size: " << s1.size() << endl;
    cout << "Top: " << s1.top() << endl;
    while(!s1.isEmpty()){
        cout << s1.pop() << "\t";
    }
}

