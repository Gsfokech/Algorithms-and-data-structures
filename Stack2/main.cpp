#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void push(Node*& top, int data){
    Node* temp = new Node;
    if(!temp){
        return;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

int isEmpty(Node* top){
    return top == NULL;
}

int pop(Node*& top){
    if(isEmpty(top)){
        cout << "The list is empty. Nothing to pop." << endl;
        return -1;
    }
    Node* temp = top;
    int data = temp->data;
    top = top->next;
    delete temp;
    return data;
}

int peek(Node* top){
    if(isEmpty(top)){
        cout << "The list is empty. Nothing to return." << endl;
        return -1;
    }
    return top->data;
}

void printStack(Node* top){
    while (top != NULL){
        cout << top->data << " -> ";
        top = top->next;
    }
    cout << "NULL" << endl;
}

void deleteStack(Node*& top){
    while (top != NULL){
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main(){
    Node* top = NULL;

    push(top, 45);
    push(top, 30);
    push(top, 15);

    printStack(top);

    cout << "Top element: " << peek(top) << endl;

    pop(top);

    printStack(top);

    deleteStack(top);

    return 0;
}
