#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // Return null character if stack is empty
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

// Function to check if expression is balanced
int isBalanced(char* exp) {
    // Create mapping
    char closing[] = {')', ']', '}'};
    char opening[] = {'(', '[', '{'};
    
    for (int i = 0; i < strlen(exp); i++) {
        // If opening bracket, push to stack
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            push(exp[i]);
        } 
        // If closing bracket, check with stack's top element
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            if (top == -1) {
                return 0; // Stack is empty but closing bracket found
            } else {
                char temp = peek();
                for (int j = 0; j < 3; j++) {
                    if (exp[i] == closing[j] && temp == opening[j]) {
                        pop();
                        break;
                    }
                }
            }
        }
    }
    return top == -1 ? 1 : 0;
}

int main() {
    char A[] = "{([a+b]*[c-d])/e}";
    printf("%d\n", isBalanced(A)); // Should print 1 (True)
 
    char B[] = "{([a+b]}*[c-d])/e}";
    printf("%d\n", isBalanced(B)); // Should print 0 (False)
 
    char C[] = "{([{a+b]*[c-d])/e}";
    printf("%d\n", isBalanced(C)); // Should print 0 (False)
 
    return 0;
}