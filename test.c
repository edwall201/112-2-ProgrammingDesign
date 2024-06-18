#include <stdio.h>
#include <stdlib.h>
typedef struct node_s {
    char data;
    struct node_s * right, * left;
} tree_t;
typedef tree_t * btree;

btree newNode(char data){
    btree node = (btree)malloc(sizeof(tree_t));
    node ->data = data;
    node ->left = NULL;
    node ->right = NULL;
    return node;
}

int search(char data[], char find, int start, int end){
    for (int i = start; i <= end; i++)
    {
        if(data[i] == find) return i;
    }
    return -1;
}

btree buildPreIn(char pre[], char in[], int start, int end, int *preindex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preindex) ++]);
    if(start == end) return node;
    int index = search(in, node->data, start, end);
    node->left = buildPreIn(pre, in, start, index - 1, preindex);
    node->right = buildPreIn(pre, in, index +1, end, preindex);
    return node;
}
btree buildPostIn(char post[], char in[], int start, int end, int *preindex){
    if(start > end) return NULL;
    btree node = newNode(post[(*preindex) --]);
    if(start == end) return node;
    int index = search(in, node->data, start, end);
    node->left = buildPostIn(post, in, start, index - 1, preindex);
    node->right = buildPostIn(post, in, index +1, end, preindex);
    return node;
}

int height(btree node){
    if(node == NULL) return 0;
    else{
        int rheight = height(node->right);
        int lheight = height(node->left);
        return (rheight > lheight)? rheight + 1: lheight +1;
    }
}

void printLevel(btree node, int level){
    if(node==NULL) return;
    if(level == 1) printf("%c", node->data);
    else if(level > 1){
        printLevel(node->left, level -1);
        printLevel(node->right, level - 1);
    }
}
void printTree(btree node){
    int h = height(node);
    for (int i = 1; i <= h; i++)
    {
        printLevel(node, i);
    }
    printf("\n");
}

int main(){
    int n = 0;
    char type1, type2;
    char data1[100], data2[100];
    scanf("%d", &n);
    scanf(" %c", &type1);
    scanf("%s", data1);
    scanf(" %c", &type2);
    scanf("%s", data2);
    btree root = NULL;
    if((type1 == 'P' && type2 == 'I') || (type1 == 'I' && type2== 'P')){
        char *pre = (type1 == 'P')?data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = 0;
        root = buildPreIn(pre, in, 0, n -1, &preIndex);
    }else if((type1 == 'O' && type2 == 'I') || (type1 == 'I' && type2 == 'O')){
        char *pre = (type1 == 'O')?data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = n - 1;
        root = buildPostIn(pre, in, 0, n - 1, &preIndex);
    }
    printTree(root);
    return 0;
}
