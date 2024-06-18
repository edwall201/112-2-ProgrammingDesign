#include <stdio.h>
#include <string.h>
typedef struct node_s {
    int id;
    int time;
    // struct node_s * nexts[30];
    int nextCount;
    int next[30];
} task_t;
typedef task_t * pTask;

void dfs(int u, task_t node[], int dp[], int pre[]){
    for (int i = 0; i < node[u].nextCount; i++)
    {
        int v = node[u].next[i];
        if(dp[v] < node[v].time + dp[u]){
            dp[v] = node[v].time + dp[u];
            pre[v] = u;
            dfs(v, node, dp, pre);
        }
    }
}

int max(int a, int b) {return (a>b)? a:b;}
void printPath(int pre[], int end_node){
    if(pre[end_node] == -1) {
        printf("%d", end_node);
        return;
    }
    printPath(pre, pre[end_node]);
    printf(" %d",end_node);
}
int main(){
    int command, M;
    scanf("%d", &command);
    scanf("%d", &M);
    task_t tasks[M+1];
    int pre[M+1];
    int dp[M+1];
    memset(pre,-1,  sizeof(pre));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= M; i++)
    {
        scanf("%d", &tasks[i].time);
        dp[i] = tasks[i].time;
        scanf("%d", &tasks[i].nextCount);
        for (int j = 0; j < tasks[i].nextCount; j++)
        {
            scanf("%d", &tasks[i].next[j]);
        }
    }
    for (int i = 1; i <= M; i++)
    {
        dfs(i, tasks, dp, pre);
    }
    if(command == 1){
        int min = 0;
        for (int i = 1; i <= M; i++)
        {
            min = max(min, dp[i]);
        }
        printf("%d\n", min);
    }
    else if(command == 2){
        int max = 0;
        int end_node = 1;
        for (int i = 1; i <= M; i++)
        {
            if(dp[i] > max) {
                max = dp[i];
                end_node = i;
            }
        }
        printPath(pre, end_node);
    }
    
    

}