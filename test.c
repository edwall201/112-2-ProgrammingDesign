#include <stdio.h>
#include <string.h>
typedef struct node_s {
    int id;
    int time;
    struct node_s * nexts[30];
    int nextCount;
    int next[30];
} task_t;
typedef task_t * pTask;

void dfs(int u, task_t nodes[], int dp[], int pre[]){
    for (int i = 0; i < nodes[u].nextCount; i++)
    {
        int v = nodes[u].next[i];
        if(dp[v] < dp[u]+nodes[v].time){
            dp[v] = dp[u]+nodes[v].time;
            pre[v] = u;
            dfs(v, nodes, dp, pre);
        }
    }
    
}
int max(int a, int b){return (a>b)?a:b;}

void printPath(int end, int pre[]){
    if(pre[end] == -1){
        printf("%d ", end);
        return;
    }
    printPath(pre[end], pre);
    printf("%d ", end);
}
int main(){
    int command = 0, M = 0;
    scanf("%d", &command);
    scanf("%d", &M);
    task_t nodes[M+1];
    int pre[M+1];
    int dp[M+1];
    memset(pre, -1, sizeof(pre));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", &nodes[i].time, &nodes[i].nextCount);
        dp[i] = nodes[i].time;
        for (int j = 0; j < nodes[i].nextCount; j++)
        {
            scanf("%d", &nodes[i].next[j]);
        }
    }
    for (int i = 1; i <= M; i++)
    {
        dfs(i, nodes, dp, pre);
    }
    if(command == 1){
        int min = 0;
        for (int i = 1; i <=M; i++)
        {
            min = max(min, dp[i]);
        }
        printf("%d\n", min);
    }else if(command == 2){
        int max = 0;
        int end_node = 1;
        for (int i = 1; i <= M; i++)
        {
            if(dp[i] > max){
                max = dp[i];
                end_node = i;
            }
        }
        printPath(end_node, pre);
        printf("\n");
        
    }
    
    
    

}