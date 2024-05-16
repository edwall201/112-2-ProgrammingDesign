#include <stdio.h>
#define MAX 100

int main()
{
    int current[MAX];
    int num_tasks[MAX];
    int machine[MAX][MAX];
    int task_len[MAX][MAX];
    int available_time[MAX];
    int prev_finish[MAX];
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", num_tasks + i);
        for (int j = 0; j < num_tasks[i]; j++)
        {
            scanf("%d %d", &machine[i][j], &task_len[i][j]);
        }
        
    }
    
}