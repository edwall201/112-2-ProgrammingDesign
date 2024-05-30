#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
    int data;
    struct dnode_s * front;
    struct dnode_s * back;
} node_t;
typedef node_t * nodep_t;

void addFront(nodep_t *head, nodep_t *tail, int data) {
    nodep_t new_node = (nodep_t)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->front = NULL;
    new_node->back = *head;
    if (*head != NULL) (*head)->front = new_node;
    *head = new_node;
    if (*tail == NULL) *tail = new_node;
}

void addBack(nodep_t *head, nodep_t *tail, int data) {
    nodep_t new_node = (nodep_t)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->back = NULL;
    new_node->front = *tail;
    if (*tail != NULL) (*tail)->back = new_node;
    *tail = new_node;
    if (*head == NULL) *head = new_node;
}

void removeFront(nodep_t *head, nodep_t *tail) {
    if (*head == NULL) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t temp = *head;
    *head = (*head)->back;
    if (*head != NULL) (*head)->front = NULL;
    else *tail = NULL;
    free(temp);
}

void removeBack(nodep_t *head, nodep_t *tail) {
    if (*tail == NULL) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t temp = *tail;
    *tail = (*tail)->front;
    if (*tail != NULL) (*tail)->back = NULL;
    else *head = NULL;
    free(temp);
}

void empty(nodep_t *head, nodep_t *tail) {
    if(*tail == NULL){printf("Double link list is empty\n"); return;}
    while (*head != NULL) {
        removeFront(head, tail);
    }
}

void insert(nodep_t *head, nodep_t *tail, int n, int data) {
    if (n <= 0) {
        printf("Invalid command\n");
        return;
    }
    nodep_t temp = *head;
    for (int i = 1; i < n && temp != NULL; i++) {
        temp = temp->back;
    }
    if (temp == NULL) {
        printf("Invalid command\n");
        return;
    }
    nodep_t new_node = (nodep_t)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->back = temp->back;
    new_node->front = temp;
    if (temp->back != NULL) temp->back->front = new_node;
    temp->back = new_node;
    if (*tail == temp) *tail = new_node;
}

void removeN(nodep_t *head, nodep_t *tail, int n) {
    if (n <= 0) {
        printf("Invalid command\n");
        return;
    }
    nodep_t temp = *head;
    for (int i = 1; i < n && temp != NULL; i++) {
        temp = temp->back;
    }
    if (temp == NULL) {
        printf("Invalid command\n");
        return;
    }
    if (temp->front != NULL) temp->front->back = temp->back;
    else *head = temp->back;
    if (temp->back != NULL) temp->back->front = temp->front;
    else *tail = temp->front;
    free(temp);
}

void print(nodep_t *head) {
    if (*head == NULL) {
        printf("Double link list is empty\n");
        return;
    }
    nodep_t temp = *head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->back;
    }
}

int main() {
    nodep_t head = NULL;
    nodep_t tail = NULL;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char command[20];
        scanf("%s", command);
        if (strcmp(command, "addFront") == 0) {
            int data;
            scanf("%d", &data);
            addFront(&head, &tail, data);
        } else if (strcmp(command, "addBack") == 0) {
            int data;
            scanf("%d", &data);
            addBack(&head, &tail, data);
        } else if (strcmp(command, "removeFront") == 0) {
            removeFront(&head, &tail);
        } else if (strcmp(command, "removeBack") == 0) {
            removeBack(&head, &tail);
        } else if (strcmp(command, "empty") == 0) {
            empty(&head, &tail);
        } else if (strcmp(command, "insert") == 0) {
            int n, data;
            scanf("%d%d", &n, &data);
            insert(&head, &tail, n, data);
        } else if (strcmp(command, "remove") == 0) {
            int n;
            scanf("%d", &n);
            removeN(&head, &tail, n);
        } else if (strcmp(command, "print") == 0) {
            print(&head);
        }
    }
    return 0;
}