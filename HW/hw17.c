#include <stdio.h>
#include <string.h>

void decodeAndPrintMatrix(char expression[], int n) {
    int matrix[n][n];
    int x = 0, y = 0, subSize = n;

    memset(matrix, -1, sizeof(matrix));

    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '2') {
            subSize /= 2;
            continue;
        }

        int value = expression[i] - '0';
        for (int j = y; j < y + subSize; j++) {
            for (int k = x; k < x + subSize; k++) {
                matrix[j][k] = value;
            }
        }

        x += subSize;
        if (x >= n) {
            x = 0;
            y += subSize;
        }
        if (y >= n) {
            y = 0;
            subSize = n;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char expression[101];
    int n;

    scanf("%s", expression);
    scanf("%d", &n);

    decodeAndPrintMatrix(expression, n);
    return 0;
}