#include<iostream>
using namespace std;
class dLinkedList{
    class Node{
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int n){
            data = n;
            prev = NULL;
            next = NULL;
        }
    };
    Node *first = NULL;
    Node *last = NULL;
    int indexOf(int n){
        int i = -1;
        Node *temp = first;
        while(temp){
            ++i;
            if(temp -> data == n){
                return i;
            }
            temp = temp -> next;
        }
        return -1;
    }
    public:
        bool isEmpty(){
            return (first == NULL);
        }
        void addLast(int n){
            Node *temp = new Node(n);
            if(isEmpty()){
                first = last = temp;
            }
            else{
                temp -> prev = last;
                last -> next = temp;
                last = temp;
            }
        }
        void addFirst(int n){
            Node *temp = new Node(n);
            if(isEmpty()){
                first = last = temp;
            }
            else{
                first -> prev = temp;
                temp -> next = first;
                first = temp;
            }
        }
        void removeFirst(){
            if(isEmpty()){
                cout << "noSuchElementException" << endl;
            }
            else if(first == last){
                first = last = NULL;
            }
            else{
                Node *temp = first -> next;
                first = temp;
                first -> prev = NULL;
            }
        }
        void removeLast(){
            if(isEmpty()){
                cout << "noSuchElementException" << endl;
            }
            else if(first == last){
                first = last = NULL;
            }
            else{
                Node *temp = last -> prev;
                last = temp;
                last -> next = NULL;
            }
        }
        bool contains(int n){
            return (indexOf(n) != -1);
        }
        int size(){
            int s = 0;
            Node *temp = first;
            while(temp){
                s++;
                temp = temp -> next;
            }
            return s;
        }
        void printListHead(){
            Node *temp = first;
            while(temp){
                cout << temp -> data << "\t";
                temp = temp -> next;
            }
        }
        void printListTail(){
            Node *temp = last;
            while(temp){
                cout << temp -> data << "\t";
                temp = temp -> prev;
            }
        }
};
int main(){
    dLinkedList d;
    d.addLast(20);
    d.addLast(30);
    d.addLast(40);
    d.addLast(50);
    d.addFirst(10);
    d.addLast(60);
    cout << "Size: " << d.size() << endl;
    cout << "Printing List From Head To Tail" << endl << "List: ";
    d.printListHead();
    cout << endl << "Printing List From Tail To Head" << endl << "List: ";
    d.printListTail();
    return 0;
}
