 #include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

// FUNCTION DECLARATIONS
node* insertatbeginning(node* head);
node* insertinbetween(node* head);
node* insertatend(node* head);
node* deletefrombeginning(node* head);
node* deleteinbetween(node* head);
node* deletefromend(node* head);
void linkedlisttraversal(node* head);

int main() {
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    node* head = (node*)malloc(sizeof(node));
    node* p = head;

    printf("ENTER THE ELEMENT: ");
    scanf("%d", &head->data);
    head->next = NULL;

    for (int i = 1; i < n; i++) {
        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &p->data);
        p->next = NULL;
    }

    printf("\nYOUR INITIAL SINGLY LINKED LIST: ");
    linkedlisttraversal(head);

    int choice;
    do {
        printf("\n\nENTER THE NUMBER CORRESPONDING TO THE TASK YOU WANT TO PERFORM: ");
        printf("\n0. EXIT\n1. INSERT AT BEGINNING\n2. INSERT AT INDEX\n3. INSERT AT END");
        printf("\n4. DELETE FROM BEGINNING\n5. DELETE AT INDEX\n6. DELETE AT END\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertatbeginning(head);
                break;
            case 2:
                head = insertinbetween(head);
                break;
            case 3:
                head = insertatend(head);
                break;
            case 4:
                head = deletefrombeginning(head);
                break;
            case 5:
                head = deleteinbetween(head);
                break;
            case 6:
                head = deletefromend(head);
                break;
            case 0:
                printf("EXITING...\n");
                break;
            default:
                printf("ENTER YOUR CHOICE IN THE RANGE OF 0-6\n");
        }

        if (choice != 0) {
            printf("\nUPDATED LINKED LIST: ");
            linkedlisttraversal(head);
        }

    } while (choice != 0);

    return 0;
}

// FUNCTION DEFINITIONS
node* insertatbeginning(node* head) {
    node* ptr = (node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT BEGINNING: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
    return head;
}

node* insertinbetween(node* head) {
    node* p = head;
    node* ptr = (node*)malloc(sizeof(node));
    int index;
    printf("ENTER THE DATA YOU WANT TO INSERT: ");
    scanf("%d", &ptr->data);
    printf("ENTER THE INDEX AT WHICH YOU WANT TO ENTER: ");
    scanf("%d", &index);
    int i = 0;
    while (i != index - 1 && p->next != NULL) {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node* insertatend(node* head) {
    node* ptr = (node*)malloc(sizeof(node));
    printf("ENTER THE DATA YOU WANT TO INSERT AT END: ");
    scanf("%d", &ptr->data);
    node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

node* deletefrombeginning(node* head) {
    if (head == NULL) return head;
    node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

node* deleteinbetween(node* head) {
    if (head == NULL) return head;
    node* p = head;
    node* q = head->next;
    int index;
    printf("ENTER THE INDEX AT WHICH YOU WANT TO REMOVE: ");
    scanf("%d", &index);
    int i = 0;
    while (i != index - 1 && q->next != NULL) {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

node* deletefromend(node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    node* p = head;
    node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

void linkedlisttraversal(node* head) {
    node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}