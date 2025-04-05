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
int main() {
    stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    return 0;
}