#include <stdio.h>

struct dice
{
    int up, down, leff, rightt, front, behind;
};


int main()
{
    struct dice arr1[2];
    struct dice arr2[2];
    for (int i = 0; i < 2; i++)
    {
        arr1[i].up = 1;
        arr1[i].front = 4;
        arr1[i].behind = 3;
        arr1[i].down = 6;
        arr1[i].leff = 5;
        arr1[i].rightt = 2;

        arr2[i].up = 1;
        arr2[i].front = 4;
        arr2[i].behind = 3;
        arr2[i].down = 6;
        arr2[i].leff = 5;
        arr2[i].rightt = 2;
    }
    int timea = 0, timeb = 0;
    scanf("%d", &timea);
    for (int i = 0; i < timea; i++)
    {
        int num1, num2 ,temp1, temp2;
        scanf("%d %d", &num1, &num2);
        if (num1 == 1) //前
        {
            temp1 = arr1[0].up;
            arr1[0].up =arr1[0].behind;
            arr1[0].behind = arr1[0].down;
            arr1[0].down = arr1[0].front;
            arr1[0].front = temp1;
        }else if (num1 == 2) //左
        {
            temp1 = arr1[0].up;
            arr1[0].up =arr1[0].rightt;
            arr1[0].rightt = arr1[0].down;
            arr1[0].down = arr1[0].leff;
            arr1[0].leff = temp1;
        }else if (num1 == 3) // 右
        {
            temp1 = arr1[0].up;
            arr1[0].up =arr1[0].leff;
            arr1[0].leff = arr1[0].down;
            arr1[0].down = arr1[0].rightt;
            arr1[0].rightt = temp1;
        }
        
        if (num2 == 1) //前
        {
            temp2 = arr1[1].up;
            arr1[1].up =arr1[1].behind;
            arr1[1].behind = arr1[1].down;
            arr1[1].down = arr1[1].front;
            arr1[1].front = temp2;
        }else if (num2 == 2) //左
        {
            temp2 = arr1[1].up;
            arr1[1].up =arr1[1].rightt;
            arr1[1].rightt = arr1[1].down;
            arr1[1].down = arr1[1].leff;
            arr1[1].leff = temp2;
        }else if (num2 == 3) // 右
        {
            temp2 = arr1[1].up;
            arr1[1].up =arr1[1].leff;
            arr1[1].leff = arr1[1].down;
            arr1[1].down = arr1[1].rightt;
            arr1[1].rightt = temp2;
        }
        
    }
    scanf("%d", &timeb);
    for (int i = 0; i < timeb; i++)
    {
        int num1, num2 ,temp1, temp2;
        scanf("%d %d", &num1, &num2);
        if (num1 == 1) //前
        {
            temp1 = arr2[0].up;
            arr2[0].up =arr2[0].behind;
            arr2[0].behind = arr2[0].down;
            arr2[0].down = arr2[0].front;
            arr2[0].front = temp1;
        }else if (num1 == 2) //左
        {
            temp1 = arr2[0].up;
            arr2[0].up =arr2[0].rightt;
            arr2[0].rightt = arr2[0].down;
            arr2[0].down = arr2[0].leff;
            arr2[0].leff = temp1;
        }else if (num1 == 3) // 右
        {
            temp1 = arr2[0].up;
            arr2[0].up =arr2[0].leff;
            arr2[0].leff = arr2[0].down;
            arr2[0].down = arr2[0].rightt;
            arr2[0].rightt = temp1;
        }
        
        if (num2 == 1) //前
        {
            temp2 = arr2[1].up;
            arr2[1].up =arr2[1].behind;
            arr2[1].behind = arr2[1].down;
            arr2[1].down = arr2[1].front;
            arr2[1].front = temp2;
        }else if (num2 == 2) //左
        {
            temp2 = arr2[1].up;
            arr2[1].up =arr2[1].rightt;
            arr2[1].rightt = arr2[1].down;
            arr2[1].down = arr2[1].leff;
            arr2[1].leff = temp2;
        }else if (num2 == 3) // 右
        {
            temp2 = arr2[1].up;
            arr2[1].up =arr2[1].leff;
            arr2[1].leff = arr2[1].down;
            arr2[1].down = arr2[1].rightt;
            arr2[1].rightt = temp2;
        }
        
    }
    for (int i = 0; i < 2; i++)
    {
        printf("%d %d %d %d %d %d\n",arr1[i].front ,arr1[i].up ,arr1[i].behind ,arr1[i].down ,arr1[i].rightt ,arr1[i].leff);
    }
    for (int i = 0; i < 2; i++)
    {
        printf("%d %d %d %d %d %d\n",arr2[i].front ,arr2[i].up ,arr2[i].behind ,arr2[i].down ,arr2[i].rightt ,arr2[i].leff);
    }
    int a_score = 0, b_score = 0;
    if (arr1[0].up == arr1[1].up) a_score = arr1[1].up;
    else a_score = arr1[0].up * arr1[1].up;
    if (arr2[0].up == arr2[1].up) b_score = arr2[1].up;
    else b_score = arr2[0].up * arr2[1].up;
    
    if(a_score > b_score) printf("A win");
    else if(a_score < b_score) printf("B win");
    else printf("Tie");
    
    
    
    
}