#include <stdio.h>

struct dice
{
    int up, down, leftt, rightt, front, behind;
};


int main()
{
    struct dice arr[4];
    int time = 0;
    int row[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i].up = 1;
        arr[i].down = 6;
        arr[i].leftt = 5;
        arr[i].rightt = 2;
        arr[i].front = 4;
        arr[i].behind = 3;
    }
    scanf("%d", &time);
    while (time--) {
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &row[i]);
            // printf("%d\n", row[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            if (row[i] == 1)
            {
                int temp = arr[i].up;
                arr[i].up = arr[i].behind;
                arr[i].behind = arr[i].down;
                arr[i].down = arr[i].front;
                arr[i].front = temp;
            }else if(row[i] == 2)
            {
                int temp = arr[i].up;
                arr[i].up = arr[i].front;
                arr[i].front = arr[i].down;
                arr[i].down = arr[i].behind;
                arr[i].behind = temp;
            }else if(row[i] == 3)
            {
                int temp = arr[i].up;
                arr[i].up = arr[i].leftt;
                arr[i].leftt = arr[i].down;
                arr[i].down = arr[i].rightt;
                arr[i].rightt = temp;
            }
            else if(row[i] == 4)
            {
                int temp = arr[i].up;
                arr[i].up = arr[i].rightt;
                arr[i].rightt = arr[i].down;
                arr[i].down = arr[i].leftt;
                arr[i].leftt = temp;
            }
        }
    }
    int count[6] = {0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(arr[j].up == i + 1) count[i] ++;
        } 
    }
    int twice_count=0;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        // printf("%d ", count[i]);
        if (count[i] == 4) {printf("18\n"); twice_count+=3; break;}
        if (count[i] == 2) twice_count++;
        else if(count[i] == 3) {twice_count = 0; break;}
        else if(count[i] != 0)sum += i+1;
        if (twice_count == 2) {printf("%d\n", 2*(i + 1)); break;}
    }

    if (twice_count == 1) printf("%d\n", sum);
    else if(twice_count == 0) printf("0\n");
    
}