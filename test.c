#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node_s {
    char data;
    struct node_s * right, * left;
} tree_t;
typedef tree_t * btree;

btree newNode(char data){
    btree node = (btree )malloc(sizeof(tree_t));
    node -> data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

int search(char pre[], int start, int end, char a){
    for (int i = start; i <= end; i++)
    {
        if(pre[i] == a )return i;
    }
    return -1;
}

btree buildPreIn(char pre[], char in[], int start, int end, int *preindex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preindex)++]);
    if(start == end) return node;
    int index = search(in, start, end, node->data);
    node ->left = buildPreIn(pre, in, start, index-1, preindex);
    node -> right = buildPreIn(pre, in, index+1, end, preindex);
    return node;
}

btree buildPostIn(char pre[], char in[], int start, int end, int *preindex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preindex)--]);
    if(start == end) return node;
    int index = search(in, start, end, node->data);
    node ->left = buildPostIn(pre, in, start, index-1, preindex);
    node -> right = buildPostIn(pre, in, index+1, end, preindex);
    return node;
}

int height(btree root){
    if(root == NULL) return 0;
    else{
        int lheight = height(root ->left);
        int rheigh = height(root -> right);
        return (lheight > rheigh)? lheight + 1: rheigh + 1;
    }
}
    
void printLevel(btree root, int count){
    if(root == NULL) return;
    if(count == 1) printf("%c", root->data);
    else if(count > 1){
        printLevel(root ->left, count -1);
        printLevel(root ->right, count -1);
    }
    
}
void printTree(btree root){
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        printLevel(root, i);
    }
}
int main(){
    int count = 0;
    char type1, type2;
    char data1[100], data2[100];
    scanf("%d", &count);
    scanf(" %c ", &type1);
    scanf("%s", data1);
    scanf(" %c ", &type2);
    scanf("%s", data2);
    btree node = NULL;
    if((type1 == 'P' && type2 == 'I') || (type1 == 'I' && type2 == 'P')){
        char *pre = (type1 == 'P')? data1: data2;
        char *in = (type1 == 'I')? data1: data2;
        int preindex = 0;
        node = buildPreIn(pre, in, 0, count - 1, &preindex);
    }else if((type1 == 'O' && type2 == 'I') || (type1 == 'I' && type2 == 'O')){
        char *post = (type1 == 'O')? data1: data2;
        char *in = (type1 == 'I')? data1: data2;
        int preindex = count - 1;
        node = buildPostIn(post, in, 0, count - 1, &preindex);
    }
    printTree(node);
}