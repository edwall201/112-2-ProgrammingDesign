#include <stdio.h>

int main()
{
    int name[3] = {0, 0, 0}, time1[3] = {0, 0, 0}, time2[3] = {0, 0, 0}, time3[3] = {0, 0, 0};
    int check = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &name[i]);
        int temp = 0;
        scanf("%d", &temp);
        for (int l = 0; l < temp; l++)
        {
            int timetemp = 0;
            scanf("%d", &timetemp);
            if (i == 0)
            {
                check += timetemp;
                time1[l] = timetemp;
            }
            else if (i == 1)
            {
                check += timetemp;
                time2[l] = timetemp;
            }
            else if (i == 2)
            {
                check += timetemp;
                time3[l] = timetemp;
            }
        }
    }
    int check1 = check;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((time1[i] == time2[j]) && (time1[i] != 0)){
                printf("%d,", name[0]);
                printf("%d,", name[1]);
                printf("%d", time2[j]);
                printf("\n");
                check1 --;
            }
        }    
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((time1[i] == time3[j]) && (time1[i] != 0)){
                printf("%d,", name[0]);
                printf("%d,", name[2]);
                printf("%d", time1[i]);
                printf("\n");
                check1 --;
            }
        }    
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((time2[i] == time3[j]) && (time2[i] != 0)){
                printf("%d,", name[1]);
                printf("%d,", name[2]);
                printf("%d", time3[j]);
                printf("\n");
                check1--;
            }
        }    
    }
    if (check1 == check){
        printf("correct\n");
    }
}