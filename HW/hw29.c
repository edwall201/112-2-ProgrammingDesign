#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

node_t *head = NULL;

void push(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node_t *temp = head;
    printf("%d\n", temp->data);
    head = head->next;
    free(temp);
}

void top() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", head->data);
}

void empty() {
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    while (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
        // printf("%d\n", temp->data);
    }
}

void print() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node_t *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "push") == 0) {
            int data;
            scanf("%d", &data);
            push(data);
        } else if (strcmp(operation, "pop") == 0) {
            pop();
        } else if (strcmp(operation, "top") == 0) {
            top();
        } else if (strcmp(operation, "empty") == 0) {
            empty();
        } else if (strcmp(operation, "print") == 0) {
            print();
        }
    }
    return 0;
}