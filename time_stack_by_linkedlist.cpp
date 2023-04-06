#include <chrono>
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
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
    int size;
    cout << "Enter the maximum size of the stack: ";
    cin >> size;
    Stack s;
    // start the timer
    auto start = high_resolution_clock::now();
    // push elements onto the stack
    for(int i=0;i<10;i++){
        push(&s, 8);
        push(&s, 10);
        push(&s, 5);
        push(&s, 11);
        push(&s, 15);
        push(&s, 23);
        push(&s, 6);
        push(&s, 18);
        push(&s, 20);
        push(&s, 17);

        display(&s);

        // pop elements from the stack
        for (int i = 0; i < 5; i++) {
            pop(&s);
        }

        display(&s);

        // push more elements onto the stack
        push(&s, 4);
        push(&s, 30);
        push(&s, 3);
        push(&s, 1);

        display(&s);
    }
    // stop the timer
    auto stop = high_resolution_clock::now();
    // calculate the time taken in seconds
    auto duration = duration_cast<nanoseconds>(stop - start);



    cout << endl;
    cout<<"max size of the in array:"<<size<<endl;
    cout << "Time taken by the stack created using a array: " << duration.count()/1000.0 << " microseconds" << endl;
    return 0;
}


