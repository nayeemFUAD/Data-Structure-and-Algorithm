#include<iostream>
#include<stack>
using namespace std;

class UQueue{
    stack<int> s1, s2;
public:
    void enqueue(int n){
        s1.push(n);
    }
    int dequeue(){
        if(s1.empty()){
            cout << "emptyQueueException" << endl;
        }
        else{
            while(!s1.empty()){
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
            int y = s2.top();
            s2.pop();
            while(!s2.empty()){
                int x = s2.top();
                s1.push(x);
                s2.pop();
            }
            return y;
        }
    }
    int size(){
        return s1.size();
    }

    bool isEmpty(){
        return s1.empty();
    }
    int front(){
        while(!s1.empty()){
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int y = s2.top();
        while(!s2.empty()){
            int x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return y;
    }
};

int main(){
UQueue q1;
q1.enqueue(10);
q1.enqueue(20);
q1.enqueue(30);
q1.enqueue(40);
cout << "Removed Element: " << q1.dequeue() << endl;
cout << "Size: " << q1.size() << endl;
cout << "Front: " << q1.front() << endl;
while(!q1.isEmpty()){
    cout << q1.dequeue() << "\t";
}
return 0;
}

