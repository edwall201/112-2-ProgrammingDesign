#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s{
    char data;
    struct node_s * right, *left;
}tree_t;
typedef tree_t *btree;

btree newNode(int data){
    btree node = (btree)malloc(sizeof(tree_t));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int search(char data[], int start, int end, char word){
    for (int i = start; i <= end ; i++)
    {
        if(data[i] == word) return i;
    }
    return -1;
}

btree buildPreI(char in[], char pre[], int start, int end, int *preIndex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preIndex)++]);
    if(start == end) return node;
    int inIndex = search(pre, start, end, node->data);
    node -> left = buildPreI(in, pre, start, inIndex-1, preIndex);
    node -> right = buildPreI(in, pre, inIndex + 1, end, preIndex);
    return node;
}

btree buildPostI(char in[], char post[], int start, int end, int *postIndex){
    if(start > end) return NULL;
    btree node = newNode(post[(*postIndex)--]);
    if(start == end) return node;
    int inIndex = search(post, start, end, node->data);
    node -> left = buildPostI(in, post, start, inIndex-1, postIndex);
    node -> right = buildPostI(in, post, inIndex + 1, end, postIndex);
    return node;
}

int height(btree node){
    if(node == NULL) return 0;
    else{
        int lheight = height(node -> left);
        int rheight = height(node -> right);
        return (lheight > rheight)? lheight + 1 : rheight + 1;
    }
}

void printLevel(btree node, int level)
{
    if(node == NULL) return;
    if(level == 1) printf("%c", node -> data);
    else if(level > 1){
        printLevel(node -> left, level - 1);
        printLevel(node -> right, level - 1);
    }
}

void printOrder(btree node){
    int h = height(node);
    for (int i = 1; i <= h; i++)
    {
        printLevel(node, i);
    }
}

int main()
{
    char seq1[21] = "", seq2[21] = "";
    char code1, code2;
    scanf(" %c", &code1);
    scanf("%s", seq1);
    scanf(" %c", &code2);
    scanf("%s", seq2);
    btree root = NULL;
    if((code1 == 'P' && code2 == 'I') || (code1 == 'I' && code2 == 'P')){
        char *pre = (code1 == 'P') ? seq1 : seq2;
        char *in = (code1 == 'I') ? seq1 : seq2;
        int preIndex = 0;
        root = buildPreI(in, pre, 0, strlen(in) - 1, &preIndex);
    }else if((code1 == 'O' && code2 == 'I') || (code1 == 'I' && code2 == 'O')){
        char *post = (code1 == 'O') ? seq1 : seq2;
        char *in = (code1 == 'I') ? seq1 : seq2;
        int postIndex = strlen(post) - 1;
        root = buildPostI(in, post, 0, strlen(in) - 1, &postIndex);
    }
    if(root != NULL) printOrder(root);
    return 0;
}