#include <stdio.h>
#include <string.h>

void decodeAndPrintMatrix(char expression[], int n)
{
    int matrix[n][n];
    int row = 0, col = 0, subSize = n, count = 0;
    memset(matrix, -1, sizeof(matrix));
    for (int i = 0; i < strlen(expression); i++)
    {

        if (expression[i] == '2')
        {
            subSize /= 2;
            // continue;
            if (subSize != 1)
            {
                continue;
            }
            else
            {
                for (int j = row; j < row + 2; j++)
                {
                    for (int k = col; k < col + 2; k++)
                    {
                        matrix[j][k] = expression[++i] - '0';
                        count++;
                        // printf("(%d, %d)\n", j, k, subSize);
                        // if (matrix[j][k] == 1)
                        // {
                        //     printf("(%d, %d)\n", j, k);
                        // }
                    }
                }
                subSize++;
                col += subSize;
                if (col >= n && (count == 24 || count == 56))
                {
                    col = 4;
                    row += subSize;
                }
                else if (col >= n && (count == 32 || count == 64))
                {
                    col = 0;
                    row += subSize;
                }
                if (count == 8 || count == 40) // if count == 8 or 40, change column & row
                {
                    col = 0;
                    row += subSize;
                }
                else if (count == 16) // if count == 16 or 48, change column & row
                {
                    subSize = n / 2;
                    row = 0;
                }
                else if (count == 48)
                {
                    subSize = n / 2;
                    row = n / 2;
                }
                if (row >= n / 2 && count == n * n / 2)
                {
                    row = n / 2;
                    col = 0;
                    subSize = n / 2;
                }
                continue;
            }
        }

        int value = expression[i] - '0';
        if (value == 0 && subSize != 1)
        {
            for (int j = row; j < row + subSize; j++)
            {
                for (int k = col; k < col + subSize; k++)
                {
                    count++;
                    matrix[j][k] = 0;
                }
            }
        }
        else if (value == 1 && subSize != 1)
        {
            for (int j = row; j < row + subSize; j++)
            {
                for (int k = col; k < col + subSize; k++)
                {
                    count++;
                    matrix[j][k] = 1;
                    // printf("(%d, %d)\n", j, k);
                }
            }
        }

        col += subSize;
        if (col >= n) // 到最後一 col 時 Change column & row
        {
            col = subSize + 2;
            row += subSize;
            // printf("%d %d\n", row, col);
        }
        else if (count == 8 || count == 40) // if count == 8 or 40, change column & row
        {
            col = 0;
            row += subSize;
        }
        else if (count == 16) // if count == 16 or 48, change column & row
        {
            subSize = n / 2;
            row = 0;
        }
        else if (count == 48)
        {
            subSize = n / 2;
            row = n / 2;
        }
        if (row >= n / 2 && count == n * n / 2)
        {
            row = n / 2;
            col = 0;
            subSize = n / 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                printf("%d,%d\n", i, j);
            }
            // printf("%d ", matrix[i][j]);
        }
        // printf("\n");
    }
}

int main()
{
    char expression[101];
    int n;

    scanf("%s", expression);
    scanf("%d", &n);
    if (expression[0] == '0')
    {
        printf("all white\n");
    }

    decodeAndPrintMatrix(expression, n);
    return 0;
}

// 2 2 2 1001 2 1001 2 1001 2 1001 22 1010 2 1001 2 1001 2 1001 2 2 1001 2 1000 2 0001 2 1101 22 1001 2 1001 2 1001 2 1001