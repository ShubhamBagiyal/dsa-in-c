#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
//FUNCTION DECLARATION'S
int isempty(node*top);
int isfull(node*top);
node*push(node*top,int x);
int pop(node**top);
void traverse(node*ptr);

int main() {
    node*top=NULL;
    top=push(top,78);top=push(top,79);top=push(top,80);top=push(top,81);top=push(top,82);top=push(top,83);top=push(top,84);
    printf("\nBEFORE POPPING\n");
    traverse(top);
    int element=pop(&top);
    printf("\nPOPPED VALUE : %d",element);
    printf("\nAFTER POPPING\n"); 
    traverse(top);
    return 0;

}
//FUNCTION DEFINITION'S
int isempty(node*top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(node*top){
    node*p=(node*)malloc(sizeof(node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
node*push(node*top,int x){
    node*n=(node*)malloc(sizeof(node));
    if(isfull(top)){
        printf("STACK OVERFLOW");
    }
    else{
        n->data=x;
        n->next=top;
        top=n;
    }
    return top;
}
int pop(node**top){
    int value;
    if(isempty(*top)){
        printf("STACK IS EMPTY");
    }
    else{
        node*p=*top;
        value=p->data;
        *top=(*top)->next;
        free(p);
    }
    return value;
}
void traverse(node*ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
