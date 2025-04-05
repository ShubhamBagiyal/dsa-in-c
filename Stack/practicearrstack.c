//PROGRAM TO PUSH NUMBERS IN ARRAY USING STACK AND PRINT THEM IN REVERSE ORDER AND NORMALLY USING 2 STACK's.
#include <stdio.h>
#include <stdlib.h>
#define size 50
typedef struct stack{
    int top;
    int arr[size];
}stack;

//FUNCTION DECLARATION's....
int isfull(stack*s);             
int isempty(stack*s);
void push(stack*s,int data);
int pop(stack*s);
int peek(stack*s);
void traverse(stack*s);

int main() {
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    push(s,1);push(s,2);push(s,3);push(s,4);push(s,5);
    printf("\nARRAY IN REVERSE ORDER..\n");
    traverse(s);

    stack*ss=(stack*)malloc(sizeof(stack));
    ss->top=-1;
    push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));
    printf("\nARRAY IN NORMAL ORDER..\n");
    traverse(ss);
    return 0;
}

//FUNCTION DEFINITION's........

int isfull(stack*s){
    if(s->top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(stack*s){
    if(s->top<0){
        return 1;
    }
    else{
        return 0;
    }
}
void push(stack*s,int data){
    if(isfull(s)){
        printf("STACK OVERFLOW...");
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}
int pop(stack*s){
    int value;
    if(isempty(s)){
        printf("STACK UNDERFLOW...");
    }
    else{
        value=s->arr[s->top];
        s->top--;
    }
    return value;
}
int peek(stack*s){
    return s->arr[s->top];
}
void traverse(stack*s){
    if(isempty(s)){
        printf("STACK IS EMPTY..");
    }
    else{
        for(int i=s->top;i>=0;i--){
            printf("%d ",s->arr[i]);
    }
}
}