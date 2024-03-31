        #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int a[], int b[], int len1, int len2) {
    int sum[100] = {0};
    int carry = 0;
    int len = len1 > len2 ? len1 : len2;
    for (int i = 0; i < len; i++) {
        sum[i] = a[i] + b[i] + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }

    if (carry > 0) {
        sum[len] = carry;
        len++;
    }

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", sum[i]);
    }
    printf("\n");
}

void subtract(int a[], int b[], int len1, int len2) {
    int diff[100] = {0};
    int borrow = 0;
    int len = len1 > len2 ? len1 : len2;
    for (int i = 0; i < len; i++) {
        int temp = a[i] - borrow;
        if (i < len2) {
            temp -= b[i];
        }
        if (temp < 0) {
            diff[i] = temp + 10;
            borrow = 1;
        } else {
            diff[i] = temp;
            borrow = 0;
        }
    }

    int i = len - 1;
    while (i >= 0 && diff[i] == 0) {
        i--;
    }

    if (i == -1) {
        printf("0\n");
    } else {
        for (; i >= 0; i--) {
            printf("%d", diff[i]);
        }
        printf("\n");
    }
}

void multiply(int a[], int b[], int len1, int len2) {
    int product[200] = {0};
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            product[i + j] += a[i] * b[j];
        }
    }

    int carry = 0;
    for (int i = 0; i < len1 + len2; i++) {
        product[i] += carry;
        carry = product[i] / 10;
        product[i] %= 10;
    }

    int i = len1 + len2 - 1;
    while (i >= 0 && product[i] == 0) {
        i--;
    }

    if (i == -1) {
        printf("0\n");
    } else {
        for (; i >= 0; i--) {
            printf("%d", product[i]);
        }
        printf("\n");
    }
}

int main() {
    int a[100] = {0};
    int b[100] = {0};
    char s1[100];
    char s2[100];
    scanf("%s", s1);
    scanf("%s", s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int negative1 = 0, negative2 = 0;

    if (s1[0] == '-') {
        negative1 = 1;
        len1--;
        memmove(s1, s1 + 1, len1);
    }

    if (s2[0] == '-') {
        negative2 = 1;
        len2--;
        memmove(s2, s2 + 1, len2);
    }

    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - i - 1] - '0';
    }
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - i - 1] - '0';
    }

    if (!negative1 && !negative2) {
        if (len1 > len2)
        {
            add(a, b, len1, len2);
            subtract(a, b, len1, len2);
            multiply(a, b, len1, len2);
        }else if (len1 == len2)
        {
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < len1; i++) {
                temp1 += a[i];
                temp2 += b[i];
            }
            if (temp1 > temp2)
            {
                add(a, b, len1, len2);
                subtract(a, b, len1, len2);
                multiply(a, b, len1, len2);
            }else if (temp1 == temp2)
            {
                add(a, b, len1, len2);
                printf("0\n");
                multiply(a, b, len1, len2);
            }
            
            else{
                add(a, b, len1, len2);
                printf("-");
                subtract(b, a, len2, len1);
                multiply(a, b, len1, len2);
            }
        }else
        {
            add(a, b, len1, len2);
            printf("-");
            subtract(b, a, len2, len1);
            multiply(a, b, len1, len2);
        }
        // add(a, b, len1, len2);
        // subtract(a, b, len1, len2);
        // multiply(a, b, len1, len2);
    } else if (negative1 && !negative2) {
        if (len1 > len2) {
            printf("-");
            subtract(a, b, len1, len2);
            printf("-");
            add(a, b, len1, len2);
            printf("-");
            multiply(a, b, len1, len2);
        } else if (len1 == len2) {
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < len1; i++) {
                temp1 += a[i];
                temp2 += b[i];
            }
            if (temp1 > temp2) {
                printf("-");
                subtract(a, b, len1, len2);
                printf("-");
                add(a, b, len1, len2);
                printf("-");
                multiply(a, b, len1, len2);
            } else {
                subtract(b, a, len2, len1);
                printf("-");
                add(a, b, len1, len2);
                printf("-");
                multiply(a, b, len1, len2);
            }
        }else{
            subtract(b, a, len2, len1);
            printf("-");
            add(a, b, len1, len2);
            printf("-");
            multiply(a, b, len1, len2);
        }
        
    } else if (!negative1 && negative2) {
        if (len1 > len2) {
            subtract(a, b, len1, len2);
            add(a, b, len1, len2);
            printf("-");
            multiply(a, b, len1, len2);
        } else if (len1 == len2) {
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < len1; i++) {
                temp1 += a[i];
                temp2 += b[i];
            }
            if (temp1 > temp2) {
                subtract(a, b, len1, len2);
                add(a, b, len1, len2);
                printf("-");
                multiply(a, b, len1, len2);
            }else if (temp1 == temp2)
            {
                printf("0\n");
                add(a, b, len1, len2);
                printf("-");
                multiply(a, b, len1, len2);
            }else {
                printf("-");
                subtract(b, a, len2, len1);
                add(a, b, len1, len2);
                printf("-");
                multiply(a, b, len1, len2);
            }
        } else {
            printf("-");
            subtract(b, a, len2, len1);
            add(a, b, len1, len2);
            printf("-");
            multiply(a, b, len1, len2);
        }

    } else if (negative1 && negative2) {
        if (len1 > len2) {
            printf("-");
            add(a, b, len1, len2);
            printf("-");
            subtract(a, b, len1, len2);
            multiply(a, b, len1, len2);
        } else if (len1 == len2) {
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < len1; i++) {
                temp1 += a[i];
                temp2 += b[i];
            }
            if (temp1 > temp2) {
                printf("-");
                add(a, b, len1, len2);
                printf("-");
                subtract(a, b, len1, len2);
                multiply(a, b, len1, len2);
            } else {
                printf("-");
                add(a, b, len1, len2);
                subtract(b, a, len2, len1);
                multiply(a, b, len1, len2);
            }

        } else {
            printf("-");
            add(a, b, len1, len2);
            subtract(b, a, len2, len1);
            multiply(a, b, len1, len2);
        }

    }

    return 0;
}
