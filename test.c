#include <stdio.h>
#include <stdlib.h>
typedef struct node_s {
    char data;
    struct node_s * right, * left;
} tree_t;
typedef tree_t * btree;
btree newTree(char data){
    btree node = (btree)malloc(sizeof(tree_t));
    node ->data = data;
    node ->left = NULL;
    node ->right = NULL;
    return node;
}
int search(char data[], char find, int start, int end){
    for (int i = start; i <= end; i++)
    {
        if(data[i]==find) return i;
    }return -1;
}
btree buildPreIn(char pre[], char in[], int start, int end, int *preIndex){
    if(start > end) return NULL;
    btree node = newTree(pre[(*preIndex)++]);
    if(start == end)return node;
    int inedx = search(in, node->data, start, end);
    node->left = buildPreIn(pre, in, start, inedx-1, preIndex);
    node->right = buildPreIn(pre, in, inedx+1, end, preIndex);
    return node;
}

btree buildPostIn(char pre[], char in[], int start, int end, int *preIndex){
    if(start > end) return NULL;
    btree node = newTree(pre[(*preIndex)--]);
    if(start == end)return node;
    int inedx = search(in, node->data, start, end);
    node->left = buildPostIn(pre, in, start, inedx-1, preIndex);
    node->right = buildPostIn(pre, in, inedx+1, end, preIndex);
    return node;
}
int height(btree node){
    if(node == NULL) return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        return (lheight> rheight)? lheight + 1:rheight +1;
    }
}

void printLevel(btree root, int i){
    if(root == NULL) return;
    if(i == 1) printf("%c", root->data);
    else if(i > 1){
        printLevel(root->left, i - 1);
        printLevel(root->right, i -1);
    }
}
void printTree(btree root, int n){
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printLevel(root, i);
    }
    printf("\n");
    
}
int main(){
    int count = 0;
    char type1, type2, data1[100], data2[100];
    scanf("%d", &count);
    scanf(" %c", &type1);
    scanf("%s", data1);
    scanf(" %c", &type2);
    scanf("%s", data2);
    btree root = NULL;
    if((type1=='P' && type2 =='I') ||(type1=='I' && type2 =='P')){
        char *pre = (type1 == 'P')? data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = 0;
        root = buildPreIn(pre, in, 0, count-1, &preIndex);
    }else if((type1=='O' && type2 =='I') ||(type1=='I' && type2 =='O')){
        char *pre = (type1 == 'O')? data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = count-1;
        root = buildPostIn(pre, in, 0, count-1, &preIndex);
    }
    printTree(root, count);
}