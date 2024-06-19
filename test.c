#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s
{
    char data;
    struct node_s *right, *left;
} tree_t;
typedef tree_t *btree;

btree newnode(char data)
{
    btree node = (btree)malloc(sizeof(tree_t));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}
int search(char in[], char data, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == data)
            return i;
    }
    return -1;
}
btree buildPreIn(char pre[], char in[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;
    btree node = newnode(pre[(*preIndex)++]);
    if (start == end)
        return node;
    int index = search(in, node->data, start, end);
    node->left = buildPreIn(pre, in, start, index - 1, preIndex);
    node->right = buildPreIn(pre, in, index + 1, end, preIndex);
    return node;
}
btree buildPostIn(char pre[], char in[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;
    btree node = newnode(pre[(*preIndex)--]);
    if (start == end)
        return node;
    int index = search(in, node->data, start, end);
    node->left = buildPostIn(pre, in, start, index - 1, preIndex);
    node->right = buildPostIn(pre, in, index + 1, end, preIndex);
    return node;
}
int height(btree node)
{
    if (node != NULL)
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        return (lheight > rheight) ? lheight + 1 : rheight + 1;
    }
    else
        return 0;
}
void printLevel(btree node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        printf("%c", node->data);
    else if (level > 1)
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}
void printTree(btree node)
{
    int h = height(node);
    for (int i = 0; i <= h; i++)
    {
        printLevel(node, i);
    }
    printf("\n");
}
int main()
{
    int count = 0;
    char type1, type2, data1[100], data2[100];
    scanf("%d", &count);
    scanf(" %c", &type1);
    scanf("%s", data1);
    scanf(" %c", &type2);
    scanf("%s", data2);
    btree root = NULL;
    if ((type1 == 'P' && type2 == 'I') || (type1 == 'I' && type2 == 'P'))
    {
        char *pre = (type1 == 'P') ? data1 : data2;
        char *in = (type1 == 'I') ? data1 : data2;
        int preIndex = 0;
        root = buildPreIn(pre, in, 0, count - 1, &preIndex);
    }else if ((type1 == 'O' && type2 == 'I') || (type1 == 'I' && type2 == 'O'))
    {
        char *pre = (type1 == 'O') ? data1 : data2;
        char *in = (type1 == 'I') ? data1 : data2;
        int preIndex = count - 1;
        root = buildPostIn(pre, in, 0, count - 1, &preIndex);
    }
    printTree(root);
}