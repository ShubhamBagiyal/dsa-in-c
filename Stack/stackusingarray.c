#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int size;
    int top;
    int*arr;
}stack;
int isempty(stack*ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(stack*ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    stack *s=(stack*)malloc(sizeof(stack));
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    if(isempty(s)){
        printf("the stack is empty ");
    }
    else{
        printf("the stack is not empty ");
    }

    return 0;
}