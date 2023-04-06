/*
#include <chrono>
#include <iostream>
using namespace std::chrono;
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
    cout << "Stack elements: ";
    for (int i = s->top; i >= 0; i--) {
        cout << s->arr[i] << " ";
    }
    cout << "\n";
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
        push(&s, 8, size);
        push(&s, 10, size);
        push(&s, 5, size);
        push(&s, 11, size);
        push(&s, 15, size);
        push(&s, 23, size);
        push(&s, 6, size);
        push(&s, 18, size);
        push(&s, 20, size);
        push(&s, 17, size);

        display(&s);

        // pop elements from the stack
        for (int i = 0; i < 5; i++) {
            pop(&s);
        }

        display(&s);

        // push more elements onto the stack
        push(&s, 4, size);
        push(&s, 30, size);
        push(&s, 3, size);
        push(&s, 1, size);

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

*/
