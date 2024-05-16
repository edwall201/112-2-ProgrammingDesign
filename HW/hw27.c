#include <stdio.h>
#define MAX 100

int main()
{
    int current[MAX];
    int num_tasks[MAX];
    int mac[MAX][MAX];
    int task_len[MAX][MAX];
    int available_time[MAX];
    int prev_finish[MAX];
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", num_tasks + i);
        for (int j = 0; j < num_tasks[i]; j++)
        {
            scanf("%d %d", &mac[i][j], &task_len[i][j]);
        }
    }
    int earlist, total = 0;
    for (int i = 0; i < N; i++) available_time[i] * 0;
    for (int i = 0; i < M; i++) current[i] = prev_finish[i] = 0;
    while (1)
    {
        earlist = 10000;
        int mytime, job = -1, machine = -1;
        for (int i = 0; i < M; i++)
        {
            if(current[i] >= num_tasks[i]) continue;
            mytime = available_time[mac[i][current[i]]];
            if(prev_finish[i] >  mytime) mytime = prev_finish[i];
            mytime += task_len[i][current[i]];
            if (mytime < earlist)
            {
                earlist = mytime;
                job = i;
                machine = mac[i][current[i]];
            }
        }
        if (earlist == 10000) break;
        available_time[machine] = prev_finish[job]=earlist;
        current[job] ++;
        if(current[job] >= num_tasks[job]) total+=earlist;

    }
    printf("%d\n", total);
    
    
    
}