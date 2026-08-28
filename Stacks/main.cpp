#include <iostream>

using namespace std;

const int MAXSIZE = 10;

struct ArrayStack{
    int top;
    int capacity;
    int* array;
};

struct ArrayStack *CreateStack(){
    ArrayStack* S = new ArrayStack;

    if(!S) return NULL;
    S -> capacity = MAXSIZE;
    S -> top = -1;
    S->array = new int[S->capacity];

    if(!S->array){
        return NULL;
    }
    return S;
}

int isEmpty(ArrayStack* S){
    return(S -> top == -1); // Если верно 1, если нет 0
}

int isFull(ArrayStack* S){
    return(S -> top == S -> capacity - 1);
}

void push(ArrayStack* S, int data){
    if(isFull(S)){
        cout << "Stack Overflow" << endl;
        return;
    }
    S -> array[++S->top] = data;
}

int pop(ArrayStack* S){
    if(isEmpty(S)){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return(S -> array[S->top--]);
}

void DeleteStack(ArrayStack* S){
    if(S){
        if(S -> array){
            delete[] S-> array;
        }
        delete S;
    }
}

int main() {
    ArrayStack* stack = CreateStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    int i = pop(stack);
    cout << i;
    i = pop(stack);
    cout << i;
    i = pop(stack);
    cout << i;
    i = pop(stack);
    cout << i;

    return 0;
}
