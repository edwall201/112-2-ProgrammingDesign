#include <stdio.h>
#include <string.h>

typedef struct node_s {
    int time;
    int nextCount;
    int next[30];
} node_t;

void dfs(int u, node_t nodes[], int dp[], int predecessor[]) {
    for (int i = 0; i < nodes[u].nextCount; i++) {
        int v = nodes[u].next[i];
        if (dp[v] < dp[u] + nodes[v].time) {
            dp[v] = dp[u] + nodes[v].time;
            predecessor[v] = u;
            dfs(v, nodes, dp, predecessor);
        }
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

void print_path(int end, int predecessor[]) {
    if (predecessor[end] == -1) {
        printf("%d ", end);
        return;
    }
    print_path(predecessor[end], predecessor);
    printf("%d ", end);
}

int main() {
    int type;
    scanf("%d", &type);
    int M;
    scanf("%d", &M);
    node_t nodes[M + 1];
    int dp[M+1];
    int predecessor[M+1];

    memset(dp, 0, sizeof(dp));
    memset(predecessor, -1, sizeof(predecessor));

    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &nodes[i].time, &nodes[i].nextCount);
        dp[i] = nodes[i].time;
        for (int j = 0; j < nodes[i].nextCount; j++) {
            scanf("%d", &nodes[i].next[j]);
        }
    }

    for (int i = 1; i <= M; i++) {
        dfs(i, nodes, dp, predecessor);
    }

    if (type == 1) {
        int min_time = 0;
        for (int i = 1; i <= M; i++) {
            min_time = max(min_time, dp[i]);
        }
        printf("%d\n", min_time);
    } else if (type == 2) {
        int max_time = 0;
        int end_node = 1;
        for (int i = 1; i <= M; i++) {
            if (dp[i] > max_time) {
                max_time = dp[i];
                end_node = i;
            }
        }
        // printf("Longest path: ");
        print_path(end_node, predecessor);
        printf("\n");
    } else if (type == 3) {
        // printf("Finding two longest paths is not implemented in this code.\n");
    }

    return 0;
}
