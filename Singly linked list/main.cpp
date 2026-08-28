#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

int list_length(Node*& head);    // Длина списка
void print_list(Node*& head);    // Печать списка
void insert_at_list(Node*& head, int data, int position); // Вставка в список
void delete_from_list(Node*& head, int pos);              // Удаление элемента

int main(){
    Node* head = NULL;

    cout << list_length(head);

    cout << endl;

    insert_at_list(head, 45, 0);
    print_list(head);
    cout << list_length(head);
    cout << endl;
    insert_at_list(head, 67, 1);
    print_list(head);
    cout << list_length(head);
    cout << endl;
    insert_at_list(head, 90, 0);
    print_list(head);
    cout << list_length(head);
    cout << endl;

    insert_at_list(head, 4, 5);
    print_list(head);
    cout << list_length(head);
    cout << endl;

    insert_at_list(head, 679, 10);
    print_list(head);
    cout << list_length(head);
    cout << endl;

    return 0;
}

int list_length(Node*& head) {
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void print_list(Node*& head){
    Node* current = head;
    while(current != NULL){
        cout << current -> data << " -> ";
        current = current -> next;
    }
    cout << "NULL" << endl;
}

void insert_at_list(Node*& head, int data, int pos){
    int k = 0;
    Node* newNode = new Node;
    Node* p;
    Node* q;

    if(!newNode){
        cout << "Memory Error" << endl;
        return;
    }

    newNode -> data = data;
    p = head;

    if(pos == 0){
        newNode -> next = p;
        head = newNode;
    } else{
        while((p!=NULL) && (k < pos)){
            k++;
            q = p;
            p = p -> next;
        }
        if (k != pos) {
            cout << "Position out of bounds" << endl;
            delete newNode;  // Освобождаем память, чтобы избежать утечек
            return;
        }
        q -> next = newNode;
        newNode -> next = p;
    }
}

void delete_from_list(Node*& head, int pos){
    int k = 0;
    Node* p;
    Node* q;

    p = head;

    if(pos == 0 ){
        head = head -> next;
        delete p;
        return;
    } else{
        while((p!=NULL) && (k < pos)){
            k++;
            q = p;
            p = p -> next;
        }
        if(p == NULL){
            cout << "Position does not exist" << endl;
        }
        else{
            q -> next = p -> next;
            delete p;
        }
    }
}
