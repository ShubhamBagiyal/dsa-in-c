#include <stdio.h>
#include <stdlib.h>
#define size 50
typedef struct stack{
    int top;
    int arr[size];
}stack;
void push(stack*s,int data){
    if(s->top < size-1){
        s->top+=1;
        s->arr[s->top]=data;
    }
    else{
        printf("stack overflow..");
    }
}
void traverse(stack*s){
    if(s->top==-1){
        printf("stack is empty\n");
    }
    else{
        for(int i =s->top;i>=0;i--){
            printf("%d ",s->arr[i]);
    }
    }
}
void pop(stack*s){
    if(s->top >=0){
        int value=s->arr[s->top];
        s->top--;
    }
    else{
        printf("stack is empty....\n");
    }
}
int main() {
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    push(s,7);push(s,8);push(s,12);push(s,13);push(s,8);push(s,9);
    printf("\nstack elements before popping...\n");
    traverse(s);

    printf("\nstack elements after popping...\n");
    pop(s);
    pop(s); 
    traverse(s);
    return 0;
}