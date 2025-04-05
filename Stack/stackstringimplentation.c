#include <stdio.h>
#include <stdlib.h>
#define size 20
typedef struct stack{
    int top;
    char arr[size];
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
void push(stack*s,char data){
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
            printf("%c ",s->arr[i]);
    }
    }
}
char pop(stack*s){
    char value;
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
    push(s,'S');push(s,'H');push(s,'U');push(s,'B');push(s,'H');push(s,'A');push(s,'M');
    traverse(s);
    stack*ss=(stack*)malloc(sizeof(stack));
    ss->top=-1;
    printf("\n");
    push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));push(ss,pop(s));
    traverse(ss);
    return 0;
}