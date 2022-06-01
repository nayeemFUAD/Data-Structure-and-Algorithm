#include<iostream>
using namespace std;
class binaryTree{
    class Node{
    public:
        int data;
        Node *leftChild;
        Node *rightChild;
        Node(int n){
            data = n;
            leftChild = NULL;
            rightChild = NULL;
        }
    };
    Node *head = NULL;
    bool isEmpty(){
        return (head == NULL);
    }
    void printPreOrder(Node *h){                //Head Left Right
        if(h == NULL){
            return;
        }
        cout << h -> data << endl;
        printPreOrder(h -> leftChild);
        printPreOrder(h -> rightChild);
    }
    void printInOrder(Node *h){                 // Left Head Right
        if(h == NULL){
            return;
        }
        printInOrder(h -> leftChild);
        cout << h -> data << endl;
        printInOrder(h -> rightChild);
    }
    void printPostOrder(Node *h){               // Left Right Head
        if(h == NULL){
            return;
        }
        printPostOrder(h -> leftChild);
        printPostOrder(h -> rightChild);
        cout << h -> data << endl;
    }
    public:
        void insertValue(int n){
            Node *temp = new Node(n);
            if(isEmpty()){
                head = temp;
            }
            else{
                Node *current = head;
                while(true){
                    if(n > current -> data){
                        if(current -> rightChild == NULL){
                            current -> rightChild = temp;
                            break;
                        }
                        current = current -> rightChild;
                    }
                    else{
                        if(current -> leftChild == NULL){
                            current -> leftChild = temp;
                            break;
                        }
                        current = current -> leftChild;
                    }
                }
            }
        }

        void printPreOrder(){
            printPreOrder(head);
        }
        void printInOrder(){
            printInOrder(head);
        }
        void printPostOrder(){
            printPostOrder(head);
        }
        bool findValue(int n){
            Node *current = head;
            while(current != NULL){
                if(n > current -> data){
                    current = current -> rightChild;
                }
                else if(n < current -> data){
                    current = current -> leftChild;
                }
                else{
                    return true;
                }
            }
            return false;
        }
};
int main(){
    binaryTree b;
    b.insertValue(30);
    b.insertValue(15);
    b.insertValue(5);
    b.insertValue(20);
    b.insertValue(18);
    b.insertValue(28);
    b.insertValue(50);
    b.insertValue(40);
    b.insertValue(42);
    b.insertValue(45);
    b.printInOrder();
    return 0;
}
