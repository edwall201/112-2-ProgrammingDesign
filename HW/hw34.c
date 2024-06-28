#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定義二元樹節點結構
typedef struct node_s {
    char data;
    struct node_s *right, *left;
} tree_t;

typedef tree_t *btree;

// 創建新節點
btree newNode(char data) {
    btree node = (btree)malloc(sizeof(tree_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 在陣列中查找字符的位置
int search(char arr[], int strt, int end, char value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// 根據前序和中序序列構建二元樹
btree buildTreeFromPreIn(char in[], char pre[], int inStrt, int inEnd, int *preIndex) {
    if (inStrt > inEnd)
        return NULL;

    btree tNode = newNode(pre[(*preIndex)++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTreeFromPreIn(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTreeFromPreIn(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// 根據後序和中序序列構建二元樹
btree buildTreeFromPostIn(char in[], char post[], int inStrt, int inEnd, int *postIndex) {
    if (inStrt > inEnd)
        return NULL;

    btree tNode = newNode(post[(*postIndex)--]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->right = buildTreeFromPostIn(in, post, inIndex + 1, inEnd, postIndex);
    tNode->left = buildTreeFromPostIn(in, post, inStrt, inIndex - 1, postIndex);

    return tNode;
}

// 計算二元樹的高度
int height(btree node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
    }
}

void printGivenLevel(btree root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(btree root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printGivenLevel(root, i);
    printf("\n");
}

int main() {
    char seq1[21] = "", seq2[21] = "";
    char orderType1, orderType2;

    // 讀取輸入順序類型和序列
    scanf(" %c", &orderType1);
    scanf("%s", seq1);
    scanf(" %c", &orderType2);
    scanf("%s", seq2);

    btree root = NULL;
    if ((orderType1 == 'P' && orderType2 == 'I') || (orderType1 == 'I' && orderType2 == 'P')) {
        char *pre = (orderType1 == 'P') ? seq1 : seq2;
        char *in = (orderType1 == 'I') ? seq1 : seq2;
        int preIndex = 0;
        root = buildTreeFromPreIn(in, pre, 0, strlen(in) - 1, &preIndex);
    } else if ((orderType1 == 'O' && orderType2 == 'I') || (orderType1 == 'I' && orderType2 == 'O')) {
        char *post = (orderType1 == 'O') ? seq1 : seq2;
        char *in = (orderType1 == 'I') ? seq1 : seq2;
        int postIndex = strlen(post) - 1;
        root = buildTreeFromPostIn(in, post, 0, strlen(in) - 1, &postIndex);
    }

    if (root != NULL) {
        printLevelOrder(root);
    }

    return 0;
}
