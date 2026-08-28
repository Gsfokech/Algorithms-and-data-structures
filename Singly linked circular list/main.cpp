#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

// Добавление узла в список
void insertNode(Node*& head, int data){
    Node* newNode = new Node;
    newNode -> data = data;

    if(head == nullptr){
        // Если список пуст, создаем узел, который ссылается на себя
        head = newNode;
        newNode -> next = head;
    } else{
        Node* temp = head;

        // Находим последний узел (тот, который ссылается на первый)
        while(temp -> next != head){
            temp = temp -> next;
        }

        // Вставляем новый узел в конец списка и корректируем ссылки
        temp -> next = newNode;
        newNode -> next = head;
    }
}

// Вставка элемента на произвольную позицию
void insertAtPos(Node*& head, int data, int pos){
    Node* newNode = new Node;
    newNode -> data = data;

    if(head == nullptr || pos == 0){
        if(head == nullptr){
            head = newNode;
            newNode -> next = head;
        } else{
            Node* temp = head;
            while (temp -> next != head){
                temp = temp -> next;
            }
            newNode -> next = head;
            temp -> next = newNode;
            head = newNode;
        }
        return;
    }

    Node* temp = head;
    for(int i = 0; i < pos - 1 && temp -> next != head; ++i){
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
}

// Удаление элемента по значению
void deleteNode(Node*& head, int value){
    if(head == nullptr){
        cout << "Список пустой, удалять нечего" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Если нужно удалить голову списка
    if(head -> data == value){
        if(head -> next == head){
            // Если список из одного элемента
            delete head;
            head = nullptr;
        }
        else{
            // Ищем последний элемент
            while(temp -> next != head){
                temp = temp -> next;
            }
            Node* toDel = head;
            temp -> next = head -> next;
            head = head -> next;
            delete toDel;
        }
        return;
    }
    prev = head;
    temp = head -> next;
    while(temp!=head && temp -> data != value){
        prev = temp;
        temp = temp -> next;
    }

    if(temp == head){
        cout << "зел с найденным значением не найден" << endl;
        return;
    }

    prev -> next = temp-> next;
    delete temp;
}

// Удаление узла по индексу
void delAtPos(Node*& head, int pos){
    if(head == nullptr){
        cout << "Список пуст, нечего удалять" << endl;
        return;
    }

    Node* temp = head;

    // Удаление головы
    if(pos == 0){
        if(head -> next == head){
            delete head;
            head = nullptr;
        }
        else{
            while (temp -> next != head){
                temp = temp -> next;
            }
            Node* toDel = head;
            temp -> next = head -> next;
            head = head -> next;
            delete toDel;
        }
        return;
    }

    // Поиск узла на заданной позиции
    Node* prev = nullptr;
    for(int i = 0; i < pos && temp -> next != head; ++i){
        prev = temp;
        temp = temp -> next;
    }

    if(temp == head){
        cout << "Позиция вне границ списка" << endl;
        return;
    }

    prev -> next = temp -> next;
    delete temp;
}

void printList(Node* head){
    if(head == nullptr){
        cout << "Список пуст" << endl;
        return;
    }
    Node* temp = head;
    do{
        cout << temp -> data << " -> ";
        temp = temp -> next;
    } while (temp != head);

    cout << "(head)" << endl;
}

int main(){

    return 0;
}