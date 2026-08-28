#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

// Вставка элемента
void Insert(Node*& head, int data, int pos){
    int k = 0;
    Node* newNode = new Node;
    if(!newNode){
        cout << "Memory error!" << endl;
        return;
    }
    newNode -> data = data;
    if(pos == 0){ // Вставка в начало списка
        newNode -> next = head;
        if(head != NULL){ // Если список не пуст, нужно обновить prev
            head -> prev = newNode;
        }
        head = newNode; // Обновляем голову
        return;
    }
    Node* temp = head;
    while((k < pos - 1) && (temp -> next != NULL)) {
        temp = temp -> next;
        k++;
    }
    if(k!=pos-1){
        cout << "Desired position does not exist" << endl;
    }
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    if(temp -> next){
        temp -> next -> prev = newNode;
    }
    temp -> next = newNode;
    return;
}

void Delete(Node*& head, int pos){
    Node* temp = head;
    int k = 0;
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    if(pos == 0){ // Удаление головы
        head = head -> next;
        if(head != NULL){ // Если список не пуст, обновляем prev
            head -> prev = NULL;
        }
        delete temp;
        return;
    }
    while((k < pos) && (temp -> next != NULL)){
        temp = temp -> next;
        k++;
    }
    if(k != pos - 1){
        cout << "Desired position does not exist" << endl;
    }
    Node* temp2 = temp -> prev;
    temp2 -> next = temp -> next;
    if(temp -> next){
        temp -> next -> prev = temp2;
    }
    delete temp;
    return;
}

void Print(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " <-> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    Insert(head, 34, 0); // Вставляем в пустой список
    Print(head);

    Insert(head, 78, 0); // Вставляем в пустой список
    Print(head);

    Insert(head, 86, 1); // Вставляем в пустой список
    Print(head);


    return 0;
}
