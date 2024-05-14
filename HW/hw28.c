#include <stdio.h>
#include <string.h>

typedef struct node_s
{
    int time;
    int nextCount;
    int next[100];
}node_t;

int max(int a, int b)
{
    return a > b ? a:b;
}

void dfs(int u, node_t nodes[], int dp[])
{
    for (int i = 0; i < nodes[u].nextCount; i++)
    {
        int v = nodes[u].next[i];
        if(dp[v] < dp[u] + nodes[v].time){
            dp[v] = dp[u] + nodes[v].time;
            dfs(v, nodes, dp);
        }
    }

}

int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        int M;
        scanf("%d", &M);
        node_t nodes[M];
        int dp[100] = {0};
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
            dfs(i, nodes, dp);
        }
        int ans = 0;
        for (int i = 1; i <= M; i++)
        {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
        
        
        
    }
}