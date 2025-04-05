#include <stdio.h>
#include <stdlib.h>
#define size 20
typedef struct stack{
    int top;
    char arr[size];
}stack;

//function declaration's...
int isFull(stack*s);
int isempty(stack*s);
void push(stack*s,char data);
void traverse(stack*s);
char pop(stack*s);
int parenthesismatching(char*exp);

//main function...
int main() {
    char expression[size];
    printf("ENTER THE EXPRESSION : ");
    scanf("%s",expression);

    if(parenthesismatching(expression)){
        printf("PARENTHESIS ARE MATCHED...");
    }
    else{
        printf("PARENTHESIS ARE NOT MATCHED...");
    }
    return 0;
}

//function definition...
int isFull(stack*s){
    if(s->top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(stack*s){
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
    if(isempty(s)){
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
    if(isempty(s)){
        printf("STACK IS EMPTY....\n");
    }
    else{
        value=s->arr[s->top];   //storing top value
        s->top--;
    }
    return value;
}
int parenthesismatching(char*exp){
    stack*s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(s,exp[i]);
        }
        else if(exp[i]==')'){
            if(isempty(s)){
                return 0;
            }
            pop(s);
        }
    }
    if(isempty(s)){
        return 1;
    }
    else{
        return 0;
    }
}