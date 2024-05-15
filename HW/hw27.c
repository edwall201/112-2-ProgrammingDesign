#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int machine;
    int time;
    int job;
} Work;

int cmp(const void *a, const void *b) {
    Work *A = (Work *)a;
    Work *B = (Work *)b;
    return A->time - B->time;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    
    Work works[M * 10];  // 存储所有工作的工序信息
    int workTime[M];     // 每个工作的总时间
    int machineTime[N];  // 每台机器的完成时间

    for (int i = 0; i < N; i++) {
        machineTime[i] = 0;
    }

    int idx = 0;  // 工作索引
    int needSort = 0; // 是否需要排序的标志

    for (int i = 0; i < M; i++) {
        workTime[i] = 0;
        int P;
        scanf("%d", &P);
        for (int j = 0; j < P; j++) {
            scanf("%d %d", &works[idx].machine, &works[idx].time);
            works[idx].job = i;
            idx++;
        }
        // 检查工序的输入顺序是否需要排序
        if (P > 1) {
            needSort = 1;
        }
    }

    // 如果需要排序，则按照工序时间排序
    // if (needSort) {
    //     qsort(works, idx, sizeof(Work), cmp);
    // }

    for (int i = 0; i < idx; i++) {
        int job = works[i].job;
        int machine = works[i].machine;
        int time = works[i].time;

        int earliestCompletionTime = machineTime[machine] > workTime[job] ? machineTime[machine] : workTime[job];
        machineTime[machine] = earliestCompletionTime + time;
        workTime[job] = machineTime[machine];
    }
    int totalSum = 0;

    for (int i = 0; i < M; i++) {
        totalSum += workTime[i];  // 计算总时间
    }
    printf("%d\n", totalSum);

    return 0;
}
