//PROGRAM TO PUSH CHARACTERS IN STRING USING STACK AND PRINT THEM IN REVERSE ORDER AND NORMALLY USING 2 STACK's.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50
typedef struct stack{
    int top;
    char arr[size];
}stack;

//FUNCTION DECLARATION's....
int isfull(stack*s);             
int isempty(stack*s);
void push(stack*s,char data);
int pop(stack*s);
int peek(stack*s);
void traverse(stack*s);

int main() {
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;

    // TAKING INPUT FROM USER
    char input[size];
    printf("Enter a string: ");
    scanf("%s", input);

    // PUSHING CHARACTERS OF STRING INTO THE STACK
    for(int i = 0; i < strlen(input); i++) {
        push(s, input[i]);
    }

    printf("\nSTRING IN REVERSE ORDER..\n");
    traverse(s);

    stack*ss=(stack*)malloc(sizeof(stack));
    ss->top=-1;

    // TRANSFERRING ELEMENTS TO SECOND STACK TO PRINT IN NORMAL ORDER
    while(!isempty(s)) {
        push(ss, pop(s));
    }
    
    printf("\nSTRING IN NORMAL ORDER..\n");
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
void push(stack*s,char data){
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
            printf("%c ",s->arr[i]);
        }
        printf("\n");
    }
}