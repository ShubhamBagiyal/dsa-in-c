#include <stdio.h>
#include <stdlib.h>
#define size 10
typedef struct stack{
    int top;
    int arr[size];
}stack;
int isFull(stack*s){
    if(s->top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(stack*s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    } 
}
void push(stack*s,int data){
    if(isFull(s)){
        printf("STACK OVERFLOW\n");
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}
void traverse(stack*s){
    if(isEmpty(s)){
        printf("STACK IS EMPTY\n");
    }
    else{
        for(int i =s->top;i>=0;i--){
            printf("%d ",s->arr[i]);
    }
    }
}
int pop(stack*s){
    int value;
    if(isEmpty(s)){
        printf("STACK IS EMPTY....\n");
    }
    else{
        value=s->arr[s->top];   //storing top value
        s->top--;
    }
    return value;
}
int main() {
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    push(s,7);push(s,8);push(s,12);push(s,13);push(s,8);push(s,9);
    printf("\nSTACK ELEMENTS BEFORE POPPING...\n");
    traverse(s);

    printf("\nPOPPED THE VALUE %d FROM STACK",pop(s));
    printf("\nSTACK ELEMENTS AFTER POPPING...\n");
    traverse(s);
    return 0;
}