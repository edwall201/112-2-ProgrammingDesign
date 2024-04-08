#include <stdio.h>
#include <stdlib.h>

struct dice {
    int up, down, left, right, ffront, bback;
};

struct dice arr[20 + 10];

int main() {
    int n, a, b, c, d, times;
    int row[4];
    n = 4; //四棵骰子
    scanf("%d", &times);

    for (int i = 0; i < n; i++) { // initialize dice
        arr[i].up = 1;
        arr[i].down = 6;
        arr[i].left = 5;
        arr[i].right = 2;
        arr[i].ffront = 4;
        arr[i].bback = 3;
    }

    while (times--) {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &row[i]);
            // printf("%d\n", row[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (row[i] == 1){      
                // printf("AAAAAAAAA");         // 向前
                int temp = arr[i].up;
                arr[i].up = arr[i].bback;
                arr[i].bback = arr[i].down;
                arr[i].down = arr[i].ffront;
                arr[i].ffront = temp;
            }else if (row[i] == 2){     
                // printf("BBBBBBBBB");     // 向後
                int temp = arr[i].up;
                arr[i].up = arr[i].ffront;
                arr[i].ffront = arr[i].down;
                arr[i].down = arr[i].bback;
                arr[i].bback = temp;
            }else if (row[i] == 3)          // 向右
            {
                // printf("CCCCCCCCC"); 
                int temp = arr[i].up;
                arr[i].up = arr[i].left;
                arr[i].left = arr[i].down;
                arr[i].down = arr[i].right;
                arr[i].right = temp;
            }else if(row[i] ==4){ 
                // printf("DDDDDDDDD");           // 向左
                int temp = arr[i].up;
                arr[i].up = arr[i].right;
                arr[i].right = arr[i].down;
                arr[i].down = arr[i].left;
                arr[i].left = temp;

            }
        }    
    }
    int ans[n], same_count[6] = {0}, first_2 = 0, second_2 = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        ans[i] = arr[i].up;
        same_count[arr[i].up - 1] ++;  
    }
    for (int i = 0; i < 6; i++)
    {
        if (same_count[i] ==1)
        {
            temp += i+1;
        }
        if (same_count[i] == 4) // all the same
        {
           printf("%d\n",18);
           break;
        }
        if (same_count[i] == 2 && first_2 ==0) 
        {
            first_2 =1;
        }else if (same_count[i] == 2 && first_2 ==1) // 2 pairs are the same
        {
            second_2 = 1;
            printf("%d\n", (i+1) * 2);
            break;
        }else if ((first_2 + second_2) == 1 && i ==5)
        {
            printf("%d\n", temp);
        }else if ((first_2 + second_2) == 0 && i ==5)
        {
            printf("%d\n",0);
           break;
        }
                
    }
    
    
    return 0;
}
