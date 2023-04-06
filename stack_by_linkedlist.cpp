/*
#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = nullptr;
    }
};

bool isEmpty(Stack* s) {
    return s->top == nullptr;
}

void push(Stack* s, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        cout << "Error: Stack Underflow\n";
        return -1;
    }
    int x = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    delete temp;
    return x;
}

int stackTop(Stack* s) {
    if (isEmpty(s)) {
        cout << "Error: Stack Underflow\n";
        return -1;
    }
    return s->top->data;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node* temp = s->top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main() {
    int maxsize,currentsize;
    cout << "Enter the maximum size of the stack: ";
    cin >> maxsize;
    cout << "Enter the size of the stack you need to create: ";
    cin >> currentsize;
    Stack s;

    // push elements onto the stack
    for(int i=0;i<currentsize;i++){
        push(&s,i);
    }
    display(&s);

    // pop elements from the stack
    for (int i = 0; i < currentsize; i++) {
        pop(&s);
    }

    display(&s);

    // push more elements onto the stack
    push(&s, 4);
    push(&s, 30);
    push(&s, 3);
    push(&s, 1);

    display(&s);

    return 0;
}
*/
