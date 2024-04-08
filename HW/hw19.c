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
        
        
        // struct dice temp = arr[];
        
        
    }
    scanf(n)
    int ans[n];
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].up);
    }
    printf("\n");
    return 0;
}
