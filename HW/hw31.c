#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
}

Node* insert(Node* head, int coeff, int exp) {
    if (coeff == 0) return head;
    Node* newNode = createNode(coeff, exp);
    if (!head || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    Node* prev = NULL;
    while (current && current->exp >= exp) {
        if (current->exp == exp) {
            current->coeff += coeff;
            free(newNode);
            return head;
        }
        prev = current;
        current = current->next;
    }
    prev->next = newNode;
    newNode->next = current;
    return head;
}

Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            append(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            append(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int coeff = poly1->coeff + poly2->coeff;
            if (coeff) {
                append(&result, coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 || poly2) {
        if (poly1) {
            append(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly2) {
            append(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    return result;
}

Node* subtract(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            append(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            append(&result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int coeff = poly1->coeff - poly2->coeff;
            if (coeff) {
                append(&result, coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 || poly2) {
        if (poly1) {
            append(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly2) {
            append(&result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    return result;
}

Node* multiply(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* start = poly2;
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = start; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            result = insert(result, coeff, exp);
        }
    }
    return result;
}

int checkzero(Node* head){
    while(head!=NULL){
        if(head->coeff!=0){
            return 0;
        }
        head = head->next;
    }
    return 1;
}

void print(Node* head) {
    if(checkzero(head)){
        printf("0\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        if (current->coeff == 0) {
            // Skip printing if coefficient is 0
            current = current->next;
            continue;
        }
        if (current->exp == 0) {
            printf("%d", current->coeff);
        } else if (current->exp == 1) {
            if (abs(current->coeff) == 1) {
                printf("%s", current->coeff > 0 ? "x" : "-x");
            } else {
                printf("%dx", current->coeff);
            }
        } else {
            if (abs(current->coeff) == 1) {
                printf("%s^%d", current->coeff > 0 ? "x" : "-x", current->exp);
            } else {
                printf("%dx^%d", current->coeff, current->exp);
            }
        }
        if (current->next != NULL && current->next->coeff > 0) {
            printf("+");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int coeff;
    char line[256];
    fgets(line, sizeof(line), stdin);
    char* ptr = line;
    int exp = 0;
    Node* temp = NULL;
    while (sscanf(ptr, "%d", &coeff) == 1) {
        append(&temp, coeff, exp++);
        ptr = strchr(ptr, ' ');
        if (ptr) ptr++;
        else break;
    }
    while (temp) {
        append(&poly1, temp->coeff, --exp);
        Node* oldTemp = temp;
        temp = temp->next;
        free(oldTemp);
    }
    fgets(line, sizeof(line), stdin);
    ptr = line;
    exp = 0;
    temp = NULL;
    while (sscanf(ptr, "%d", &coeff) == 1) {
        append(&temp, coeff, exp++);
        ptr = strchr(ptr, ' ');
        if (ptr) ptr++;
        else break;
    }
    while (temp) {
        append(&poly2, temp->coeff, --exp);
        Node* oldTemp = temp;
        temp = temp->next;
        free(oldTemp);
    }
    Node* sum = add(poly1, poly2);
    Node* diff = subtract(poly1, poly2);
    Node* prod = multiply(poly1, poly2);
    print(sum);
    print(diff);
    print(prod);
    return 0;
}
