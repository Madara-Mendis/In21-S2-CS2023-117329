/*
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

struct Stack {
    int arr[MAX_SIZE];
    int top;

    Stack() {
        top = -1;
    }
};

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s, int size) {
    return s->top == size - 1;
}

void push(Stack* s, int x, int size) {
    if (isFull(s, size)) {
        cout << "Error: Stack Overflow\n";
        return;
    }
    s->arr[++s->top] = x;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        cout << "Error: Stack Underflow\n";
        return -1;
    }
    return s->arr[s->top--];
}

int stackTop(Stack* s) {
    if (isEmpty(s)) {
        cout << "Error: Stack Underflow\n";
        return -1;
    }
    return s->arr[s->top];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return;
    }
    std::cout << "Stack elements: ";
    for (int i = s->top; i >= 0; i--) {
        cout << s->arr[i] << " ";
    }
    cout << "\n";
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
        push(&s,i,maxsize);
    }
    display(&s);

    // pop elements from the stack
    for (int i = 0; i < currentsize; i++) {
        pop(&s);
    }

    display(&s);

    // push more elements onto the stack
    push(&s, 4,maxsize);
    push(&s, 30,maxsize);
    push(&s, 3,maxsize);
    push(&s, 1,maxsize);

    display(&s);

    return 0;
}

*/
