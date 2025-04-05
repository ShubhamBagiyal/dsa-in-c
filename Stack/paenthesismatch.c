#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct stack {
    int top;
    char arr[size];
} stack;

int isFull(stack *s) {
    if (s->top == size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(stack *s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    } 
}

void push(stack *s, char data) {
    if (isFull(s)) {
        printf("STACK OVERFLOW\n");
    }
    else {
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(stack *s) {
    char value;
    if (isEmpty(s)) {
        printf("STACK IS EMPTY....\n");
        return '\0';
    }
    else {
        value = s->arr[s->top];
        s->top--;
    }
    return value;
}

void traverse(stack *s) {
    if (isEmpty(s)) {
        printf("STACK IS EMPTY\n");
    }
    else {
        for (int i = s->top; i >= 0; i--) {
            printf("%c ", s->arr[i]);
        }
        printf("\n");
    }
}

int parenthesismatch(char *exp) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(s, exp[i]);
        }
        else if (exp[i] == ')') {
            if (isEmpty(s)) {
                free(s);
                return 0;
            }
            pop(s);
        }
    }

    if (isEmpty(s)) {
        free(s);
        return 1;
    }
    else {
        free(s);
        return 0;
    }
}

int main() {
    char expression[size];
    
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (parenthesismatch(expression)) {
        printf("Parentheses are balanced.\n");
    }
    else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}