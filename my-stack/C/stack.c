#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

/* Initialize the stack: set top to -1 meaning empty */
void init(struct Stack *s) {
    s->top = -1;
}

/* Return 1 if the stack is empty, 0 otherwise */
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

/* Return 1 if the stack is full, 0 otherwise */
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

/* Push a value: return 1 on success, 0 if the stack is full */
int push(struct Stack *s, int value) {
    if (isFull(s)) {
        return 0;
    }
    s->top++;
    s->data[s->top] = value;
    return 1;
}

/* Pop the top value into *value: return 1 on success, 0 if the stack is empty */
int pop(struct Stack *s, int *value) {
    if (isEmpty(s)) {
        return 0;
    }
    *value = s->data[s->top];
    s->top--;
    return 1;
}

/* Read the top value into *value: return 1 on success, 0 if the stack is empty */
int peek(struct Stack *s, int *value) {
    if (isEmpty(s)) {
        return 0;
    }
    *value = s->data[s->top];
    return 1;
}

int main() {
    struct Stack s;
    int value;

    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    if (peek(&s, &value)) {
        printf("stack top: %d\n", value);
    }

    while (pop(&s, &value)) {
        printf("popped: %d\n", value);
    }

    if (!pop(&s, &value)) {
        printf("stack is empty, pop failed\n");
    }

    return 0;
}
