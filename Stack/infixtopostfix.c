#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

typedef struct stack {
    int top;
    char arr[size];
} stack;

int isFull(stack *s);
int isEmpty(stack *s);
void push(stack *s, char data);
char pop(stack *s);
int stacktop(stack *s);
char *infixtopostfix(char *infix);
int precedence(char ch);
int isOperator(char ch);

int main() {
    char *infix = "a+b*c*d-b";
    printf("postfix is %s", infixtopostfix(infix));
    return 0;
}

int stacktop(stack *s) {
    return s->arr[s->top];
}

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
    if (!isFull(s)) {
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

char *infixtopostfix(char *infix) {
    stack *ss = (stack *)malloc(sizeof(stack));
    ss->top = -1;
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            while (!isEmpty(ss) && precedence(infix[i]) <= precedence(stacktop(ss))) {
                postfix[j] = pop(ss);
                j++;
            }
            push(ss, infix[i]);
            i++;
        }
    }
    while (!isEmpty(ss)) {
        postfix[j] = pop(ss);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    }
    else if (ch == '+' || ch == '-') {
        return 2;
    }
    else {
        return 0;
    }
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    else {
        return 0;
    }
}