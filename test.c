#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node_s {
    char data;
    struct node_s * right, * left;
} tree_t;
typedef tree_t * btree;

btree newNode(char data){
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int search(char data[], int start, int end,  char a){
    for (int i = start; i <= end; i++)
    {
        if(data[i] == a) return i;
    }
    return -1;
}
btree buildPreIn(char pre[], char in[], int start, int end, int *preindex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preindex)++]);
    if(start == end) return node;
    int index = search(in, start, end, node->data);
    node->left = buildPreIn(pre, in, start, index - 1,  preindex);
    node->right = buildPreIn(pre, in, index+1, end,  preindex);
    return node;
}

btree buildPostIn(char pre[], char in[], int start, int end, int *preindex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preindex)--]);
    int index = search(in, start, end, node->data);
    if(start == end) return node;
    node->left = buildPostIn(pre, in, start, index - 1,  preindex);
    node->right = buildPostIn(pre, in, index+1, end,  preindex);
    return node;
}

int height(btree node){
    if(node == NULL) return 0;
    else{
        int lheight = height(node ->left);
        int rheight = height(node->right);
        return (lheight>rheight)?lheight+1: rheight+1;
    }
}

void printTreeLevel(btree node, int level){
    if(node == NULL) return;
    if(level == 1) printf("%c", node->data);
    else if(level > 1){
        printTreeLevel(node -> left, level - 1);
        printTreeLevel(node -> right, level-1);
    }
}

void printTree(btree node){
    int h = height(node);
    for (int i = 0; i <= h; i++)
    {
        printTreeLevel(node, i);
    }
    
}
int main(){
    int count = 0;
    char type1, type2;
    char data1[100], data2[100];
    scanf("%d", &count);
    scanf(" %c", &type1);
    scanf("%s", data1);
    scanf(" %c", &type2);
    scanf("%s", data2);
    btree node = NULL;
    if((type1 == 'P' && type2 == 'I') || (type1 == 'I' && type2 == 'P')){
        char *pre = (type1 == 'P')? data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = 0;
        node = buildPreIn(pre, in, 0, count, &preIndex);
    }else if((type1 == 'O' && type2 == 'I') || (type1 == 'I' && type2 == 'O')){
        char *post = (type1 == 'O')? data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = count-1;
        node = buildPostIn(post, in, 0, count, &preIndex);
    }
    printTree(node);

}