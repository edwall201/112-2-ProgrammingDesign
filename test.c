#include <stdio.h>
#include <stdlib.h>
typedef struct node_s{
    char data;
    struct node_s *right, *left;
}nodes_t;
typedef nodes_t *btree;

int search(char data[], int start, int end, char a){
    for (size_t i = start; i <= end; i++)
    {
        if(data[i] == a) return i;
    }
    return -1;
}

btree newNode(int data){
    btree node = (btree)malloc(sizeof(nodes_t));
    node -> data  = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;

}
btree buildPreIn(char pre[], char in[], int start, int end, int *preIndex){
    if(start > end) return NULL;
    btree node = newNode(pre[(*preIndex)++]);
    if(start == end) return node;
    int inIndex = search(in, start, end, node->data);
    node -> left = buildPreIn(pre, in, start, inIndex-1, preIndex);
    node -> right = buildPreIn(pre, in, inIndex+1, end, preIndex);
    return node;
}
btree buildPostIn(char post[], char in[], int start, int end, int *postIndex){
    if(start > end) return NULL;
    btree node = newNode(post[(*postIndex)--]);
    if(start == end) return node;
    int inIndex = search(in, start, end, node->data);
    node -> left = buildPostIn(post, in, start, inIndex-1, postIndex);
    node -> right = buildPostIn(post, in, inIndex+1, end, postIndex);
    return node;
}

int height(btree pre){
    if(pre == NULL) return 0;
    else{
        int right = height(pre->left);
        int left = height(pre->right);
        return (right > left)? right+1:left+1;
    }
}

void printLevel(btree node, int h){
    if(node == NULL) return;
    if(h == 1) printf("%c", node->data);
    printLevel(node->left, h-1);
    printLevel(node->right, h-1);
}

void printOrder(btree node, int num){
    int h = height(node);
    for (int i = 1; i <= h; i++)
    {
        printLevel(node, i);
    }
    
}
int main(){
    int num = 0;
    scanf("%d", &num);
    char type1, type2;
    char data1[20] = "", data2[20] = "";
    scanf(" %c", &type1);
    scanf("%s", data1);
    scanf(" %c", &type2);
    scanf("%s", data2);
    btree node = NULL;
    if ((type1 == 'P' && type2 == 'I') || (type1 == 'I' && type2 == 'P'))
    {
        char *pre = (type1 == 'P')? data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int preIndex = 0;
        node = buildPreIn(pre, in, 0, num - 1, &preIndex);
    }else if((type1 == 'O' && type2 == 'I' || (type1 == 'I' && type2 == 'O')))
    {
        char *post = (type1 == 'O')? data1:data2;
        char *in = (type1 == 'I')? data1:data2;
        int postIndex = num-1;
        node = buildPostIn(post, in, 0, num, &postIndex);
    }
    // printf("%c", node->data);
    printOrder(node,num);
    return 0;
}