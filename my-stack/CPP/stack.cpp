#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    /* Constructor: set top to -1 meaning empty */
    Stack() {
        top = -1;
    }

    /* Return true if the stack is empty, false otherwise */
    bool isEmpty() {
        return top == -1;
    }

    /* Return true if the stack is full, false otherwise */
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    /* Push a value: return true on success, false if the stack is full */
    bool push(int value) {
        if (isFull()) {
            return false;
        }
        top++;
        data[top] = value;
        return true;
    }

    /* Pop the top value into value: return true on success, false if the stack is empty */
    bool pop(int &value) {
        if (isEmpty()) {
            return false;
        }
        value = data[top];
        top--;
        return true;
    }

    /* Read the top value into value: return true on success, false if the stack is empty */
    bool peek(int &value) {
        if (isEmpty()) {
            return false;
        }
        value = data[top];
        return true;
    }
};

int main() {
    Stack s;
    int value;

    s.push(10);
    s.push(20);
    s.push(30);

    if (s.peek(value)) {
        cout << "stack top: " << value << endl;
    }

    while (s.pop(value)) {
        cout << "popped: " << value << endl;
    }

    if (!s.pop(value)) {
        cout << "stack is empty, pop failed" << endl;
    }

    return 0;
}
