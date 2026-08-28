#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* create_node(int data){
    Node* node = new Node;
    node -> data = data;
    node -> prev = nullptr;
    node -> next = nullptr;
    return node;
}

void insert_front(Node*& head, Node*& tail, int data){
    Node* node = create_node(data);

    if(head != nullptr){
        head -> prev = node;
    } else{
        tail = node;
    }
    head = node;
}

void insert_back(Node*& head, Node*& tail, int data){
    Node* node = create_node(data);

    if(tail!= nullptr){
        tail -> next = node;
    } else{
        head = node;
    }
    tail = node;
}

void insert(Node*& head, Node*& tail, int data, int pos){

    if(pos == 0){
        insert_front(head, tail, data);
        return;
    }

    Node* temp = head;
    for(int i = 0; i < pos - 1 && temp != nullptr; i++){
        temp = temp -> next;
    }
    if(temp == nullptr){
        cout << "Индекс за границами массива" << endl;
        return;
    }

    Node* node = create_node(data);
    node -> next = temp -> next;
    node -> prev = temp;
    if(temp -> next != nullptr){
        temp -> next -> prev = node;
    } else{
        tail = node;
    }
    temp -> next = node;
}

int get_el(Node* head, int ind) {
    Node* temp = head;
    int count = 0;
    while(temp!= nullptr){
        if(count == ind){
            return temp -> data;
        }
        count++;
        temp = temp -> next;
    }
    cout << "Индекс за границами массива" << endl;
    return -1;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

//        insertAtHead(head, tail, 10);
//        insertAtTail(head, tail, 20);
//        insertAtTail(head, tail, 30);
//        insertAtTail(head, tail, 40);

//        printList(head);
//
//        insertAtPos(head, tail, 25, 2);
//
//        printList(head);
//
//        cout << getElAt(head, 3) << endl;
//
//        deleteNode(head, tail, 2);
//
//        printList(head);
//
//        deleteFirst(head, tail);
//
//        printList(head);
//
//        deleteLast(head, tail);
//
//        printList(head)

    return 0;
}