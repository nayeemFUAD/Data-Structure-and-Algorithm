#include<iostream>
using namespace std;
class sLinkedList{
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
            if(isEmpty()){
                first = last = temp;
            }
            else{
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
                temp -> next = first;
                first = temp;
            }
        }
        void removeLast(){
            if(isEmpty()){
                cout << "noSuchElementException" << endl;
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
        void removeFirst(){
            if(isEmpty()){
                cout << "noSuchElementException" << endl;
            }
            else{
                first = first -> next;
            }
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
        int indexOf(int n){
            int i = 0;
            Node *temp = first;
            while(temp){
                if(temp -> data == n){
                    return i;
                }
                i++;
                temp = temp -> next;
            }
            return -1;
        }
        bool contains(int n){
            return (indexOf(n) != -1);
        }
        void printList(){
            Node *temp = first;
            while(temp){
                cout << temp -> data << "\t";
                temp = temp -> next;
            }
        }
        void reverseList(){
            Node *previous = first;
            Node *present = previous -> next;
            Node *NEXT;
            while(present != NULL){
                NEXT = present -> next;
                present -> next = previous;
                previous = present;
                present = NEXT;
            }
            last = first;
            last -> next = NULL;
            first = previous;
        }
};
int main(){
    sLinkedList n;
    n.addLast(20);
    n.addLast(30);
    n.addLast(40);
    n.addFirst(10);
    n.addLast(50);
    n.addLast(60);
    cout << "Size: " << n.size() << endl;
    cout << "List: ";
    n.printList();
    n.reverseList();
    cout << endl << "After Reverse" << endl;
    cout << "List: ";
    n.printList();
    return 0;
}

