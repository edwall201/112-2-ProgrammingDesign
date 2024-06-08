#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int time;
    int waiteNodeNum;
    int waiteNode[100];
    struct node_s* next;
} node_t;

typedef node_t* nodep;

int main() {
    int N, M, i, j, k, max;
    scanf("%d", &N); // 讀取測試組數
    for (i = 0; i < N; i++) {
        scanf("%d", &M); // 讀取每組的項目節點數
        nodep nodes = (nodep)malloc(sizeof(node_t) * M);
        int* timeToReach = (int*)malloc(sizeof(int) * M);

        // 讀取每個節點的信息
        for (j = 0; j < M; j++) {
            scanf("%d %d", &nodes[j].time, &nodes[j].waiteNodeNum);
            for (k = 0; k < nodes[j].waiteNodeNum; k++) {
                scanf("%d", &nodes[j].waiteNode[k]);
            }
            timeToReach[j] = nodes[j].time; // 初始化到達時間
        }

        // 計算每個節點的最長到達時間
        for (j = 0; j < M; j++) {
            for (k = 0; k < nodes[j].waiteNodeNum; k++) {
                int nodeIndex = nodes[j].waiteNode[k] - 1;
                if (timeToReach[nodeIndex] < timeToReach[j] + nodes[nodeIndex].time) {
                    timeToReach[nodeIndex] = timeToReach[j] + nodes[nodeIndex].time;
                }
            }
        }

        // 找到最大值即為項目所需的總時間
        max = timeToReach[0];
        for (j = 1; j < M; j++) {
            if (timeToReach[j] > max) {
                max = timeToReach[j];
            }
        }

        printf("%d\n", max); // 輸出每組項目的總時間

        // 釋放動態分配的內存
        free(nodes);
        free(timeToReach);
    }
    return 0;
}
