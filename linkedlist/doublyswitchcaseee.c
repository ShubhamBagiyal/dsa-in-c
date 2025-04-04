#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*next;
    struct node*prev;
}node;
node*insertatbeg(node*head){
    node*p=head;
    node*ptr=(node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT BEGINNING : ");
    scanf("%d",&ptr->data);
    p->prev=ptr;
    ptr->next=p;
    head=ptr;
    return head;
}
node*insertatindex(node*head){
    node*p=head;
    int index;
    printf("ENTER THE INDEX AT WHICH YOU WANT TO ENTER : ");
    scanf("%d",&index);
    node*q=(node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT INDEX : ");
    scanf("%d",&q->data);
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    q->next=p->next;
    q->prev=p;
    p->next=q;
    (q->next)->prev=q;
    return head;

}
node*insertatend(node*head){
    node*p=head;
    node*q=(node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT END : ");
    scanf("%d",&q->data);
    while(p->next!=NULL){
        p=p->next;
    }
    q->prev=p;
    p->next=q;
    return head;
}
node*deletefrombeg(node*head){
    node*p=head;
    head=head->next;
    free(p);
    return head;
}
node*deleteatindex(node*head){
    node*p=head;
    node*q=head->next;
    int index;
    printf("ENTER THE INDEX AT WHICH YOU WANT TO DELETE : ");
    scanf("%d",&index);
    int i = 0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;

    free(q);
    return head;
}
node*deleteatend(node*head){
    node*p=head;
    node*q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;

}
void traverse(node*head){
    node*ptr=head;
    while(ptr!=NULL){
        printf(" %d",ptr->data);
        ptr=ptr->next;
    }
}

int main() {
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS YOU WANT: ");
    scanf("%d", &n);
    node* head = (node*)malloc(sizeof(node));
    printf("ENTER THE FIRST ELEMENT: ");
    scanf("%d", &head->data);
    head->next = NULL;
    head->prev = NULL;
    node* p = head;  
    for (int i = 1; i < n; i++) {
        node* ptr = (node*)malloc(sizeof(node));
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        ptr->prev = p;
        p->next = ptr;
        p = ptr; 
    }

    printf("\nYOUR DOUBLY LINKED LIST BEFORE UPDATION : ");
    traverse(head);
    printf("\n");
    int choice;

    do {
        printf("\nYOUR LINKED LIST: ");
        traverse(head);
        printf("\n\nENTER THE NUMBER CORRESPONDING TO THE TASK YOU WANT TO PERFORM: ");
        printf("\n0. EXIT\n1. INSERT AT BEGINNING\n2. INSERT AT INDEX\n3. INSERT AT END");
        printf("\n4. DELETE FROM BEGINNING\n5. DELETE AT INDEX\n6. DELETE AT END\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = insertatbeg(head);
                break;
            case 2:
                head = insertatindex(head);
                break;
            case 3:
                head = insertatend(head);
                break;
            case 4:
                head = deletefrombeg(head);
                break;
            case 5:
                head = deleteatindex(head);
                break;
            case 6:
                head = deleteatend(head);
                break;
            case 0:
                printf("EXITING...\n");
                break;
            default:
                printf("ENTER YOUR CHOICE IN THE RANGE OF 0-6\n");
        }
    } while (choice != 0);

    return 0;
}

