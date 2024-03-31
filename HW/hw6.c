#include <stdio.h>
void shape1(int m)
{
    char item[3] = {'A', 'B', 'C'};
    for (int i = m; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            printf("#");
        }
        printf("*");
        if ((m - i) > 0)
        {
            int temp = (m -1 - i) % 3;
            for (int l = 0; l < (m - i); l++)
            {
                printf("%c", item[temp]);
                printf("*");
            }
        }
        for (int j = 1; j < i; j++)
        {
            printf("#");
        }
        printf("\n");

    }
}

void shape2(int m)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        int temp = 2 * (m - i + 1);
        for (int j =0; j < temp; j++){
            printf("*");
        }
        for (int j = i; j > 0; j--)
        {
            printf("%d", j);
        }

    printf("\n");
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1 && m >= 2 && m <= 9)
    {
        shape1(m);
    }
    else if (n == 2 && m >= 2 && m <= 9)
    {
        shape2(m);
    }
    else
    {
        printf("error\n");
    }
}