#include<iostream>
using namespace std;

class LinkedList{
    class Node{
    public:
        int data;
        Node *next;
        Node(int n){
            data = n;
            next = NULL;
        }
    };
    Node *first = NULL;
    Node *last = NULL;
    public:
        bool isEmpty(){
            return (first == NULL);
        }
        void addLast(int n){
            Node *temp = new Node(n);
            if(first == NULL){
                first = last = temp;
            }
            else{
                last -> next = temp;
                last = temp;
            }
        }
        void addFirst(int n){
            Node *temp = new Node(n);
            if(first == NULL){
                first = last = temp;
            }
            else{
                temp -> next = first;
                first = temp;
            }
        }
        void removeFirst(){
            if(isEmpty()){
                cout << "emptyLinkedListException" << endl;
            }
            else if(first == last){
                first = last = NULL;
            }
            else{
                Node *temp = first -> next;
                first = temp;
            }
        }
        void removeLast(){
            if(isEmpty()){
                cout << "emptyLinkedListException" << endl;
            }
            else if(first == last){
                first = last = NULL;
            }
            else{
                Node *temp = first;
                while(temp){
                    if(temp -> next == last){
                        break;
                    }
                    temp = temp -> next;
                }
                last = temp;
                last -> next = NULL;
            }
        }
        int size(){
            int s = 0;
            Node *temp = first;
            while(temp){
                s = s + 1;
                temp = temp -> next;
            }
            return s;
        }
        int indexOf(int n){
            int index = -1;
            Node *temp = first;
            while(temp){
                index = index + 1;
                if(temp -> data == n){
                    return index;
                }
                temp = temp -> next;
            }
            return -1;
        }
        bool contains(int n){
            return (indexOf(n) != -1);
        }
        void printLinkedList(){
            Node *temp = first;
            while(temp){
                cout << temp -> data << endl;
                temp = temp -> next;
            }
        }
};

int main(){
    LinkedList n;
    n.addLast(10);
    n.addFirst(0);
    n.removeLast();
    n.addFirst(-10);
    n.addLast(20);
    n.printLinkedList();
    return 0;
}
