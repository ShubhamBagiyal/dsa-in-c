#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
// FUNCTION DECLARATIONS
node* insertataend(node* head);
node* insertatindex(node* head);
node* deletefrombeg(node* head);
node* deleteatindex(node* head);
node* deletefromend(node* head);
void traverse(node* head);

int main() {
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS YOU WANT: ");
    scanf("%d", &n);   
    node* head = (node*)malloc(sizeof(node));
    printf("ENTER THE FIRST ELEMENT: ");
    scanf("%d", &head->data);
    node* p = head;
    for (int i = 1; i < n; i++) {
        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &p->data);
        p->next = head;
    }
    printf("\nYOUR INITIAL CIRCULAR LINKED LIST: ");
    traverse(head);
    int choice;
    do {
        printf("\n\nENTER THE NUMBER CORRESPONDING TO THE TASK YOU WANT TO PERFORM: ");
        printf("\n0. EXIT\n1. INSERT AT END\n2. INSERT AT INDEX");
        printf("\n3. DELETE FROM BEGINNING\n4. DELETE AT INDEX\n5. DELETE AT END\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertataend(head);
                break;
            case 2:
                head = insertatindex(head);
                break;
            case 3:
                head = deletefrombeg(head);
                break;
            case 4:
                head = deleteatindex(head);
                break;
            case 5:
                head = deletefromend(head);
                break;
            case 0:
                printf("EXITING...\n");
                break;
            default:
                printf("ENTER YOUR CHOICE IN THE RANGE OF 0-5\n");
        }

        if (choice != 0) {
            printf("\nUPDATED CIRCULAR LINKED LIST: ");
            traverse(head);
        }

    } while (choice != 0);

    return 0;
}
// FUNCTION DEFINITIONS
node* insertataend(node* head) {
    node* q = (node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT END: ");
    scanf("%d", &q->data);
    node* p = head;
    
    while (p->next != head) {
        p = p->next;
    }
    q->next = head;
    p->next = q;
    return head;
}

node* insertatindex(node* head) {
    node* p = head;
    int index;
    printf("ENTER THE INDEX AT WHICH YOU WANT TO ENTER: ");
    scanf("%d", &index);

    node* q = (node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT THE INDEX: ");
    scanf("%d", &q->data);
    int i = 0;
    
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    q->next = p->next;
    p->next = q;
    return head;
}

node* deletefrombeg(node* head) {
    node* p = head;
    node* q = head->next;
    
    while (q->next != head) {
        q = q->next;
    }
    q->next = p->next;
    head = head->next;
    free(p);
    return head;
}

node* deleteatindex(node* head) {
    node* p = head;
    node* q = head->next;
    int index;
    printf("ENTER THE INDEX AT WHICH YOU WANT TO DELETE: ");
    scanf("%d", &index);
    int i = 0;
    
    while (i != index - 1) {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

node* deletefromend(node* head) {
    node* p = head;
    node* q = head->next;
    
    while (q->next != head) {
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
    return head;
}

void traverse(node* head) {
    node* ptr = head;
    if (head == NULL) return;
    
    do {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
    printf("\n");
}