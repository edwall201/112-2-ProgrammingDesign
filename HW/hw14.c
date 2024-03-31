#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int a[], int b[]) {
    int sum[100] = {0};
    int carry = 0;
    int len = 0;
    for (int i = 0; i < 100; i++) {
        if (a[i] == 0 && b[i] == 0) {
            len = i;
            break;
        }
        sum[i] = a[i] + b[i] + carry;
        carry = sum[i] / 10;
        sum[i] %= 10;
    }

    // Check if there is a carry in the last calculation
    if (carry > 0) {
        sum[len] = carry;  // Add the carry as the last digit
        len++;  // Update the length to include the extra digit
    }

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", sum[i]);
    }
    printf("\n");
}

void subtract(int a[], int b[]) {
    int sum[100] = {0};
    int borrow = 0;
    int len = 0;
    for (int i = 0; i < 100; i++) {
        if (a[i] == 0 && b[i] == 0) {
            len = i;
            break;
        }
        int temp = a[i] - borrow;
        if (temp < b[i]) {
            sum[i] = temp + 10 - b[i];
            borrow = 1;
        } else {
            sum[i] = temp - b[i];
            borrow = 0;
        }
    }

    int i = len - 1;
    while (i >= 0 && sum[i] == 0) {
        i--;
    }

    if (i == -1) {
        printf("0\n");
    } else {
        for (; i >= 0; i--) {
            printf("%d", sum[i]);
        }
        printf("\n");
    }
}

void multiply(int a[], int b[]) {
    int product[200] = {0}; // 最大可能位数为两个数位数之和
    int len1 = 0, len2 = 0;
    for (int i = 0; i < 100; i++) {
        if (a[i] != 0) {
            len1 = i + 1;
        }
        if (b[i] != 0) {
            len2 = i + 1;
        }
    }

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            product[i + j] += a[i] * b[j];
        }
    }

    for (int i = 0; i < len1 + len2; i++) {
        product[i + 1] += product[i] / 10;
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

    // if (a[0] == 0 && b[0]==0)
    // {
    //     printf("0\n");
    //     printf("0\n");
    //     printf("0\n");
    // }else 
    if (!negative1 && !negative2)
    { 
        if (len1 > len2)
        {
            add(a, b);
            subtract(a, b);
            multiply(a, b);
        }else
        {
            add(a, b);
            printf("-");
            subtract(b, a);
            multiply(a, b);
        }
        
    }
    else if (negative1 && !negative2)
    {
        subtract(b, a);
        printf("-");
        add(a, b);
        printf("-");
        multiply(a, b);
    }
    else if (!negative1 && negative2)
    {
        if (len1 > len2)
        {
            subtract(a, b);
            add(a, b);
            printf("-");
            multiply(a, b);
        }else if (len1 == len2)
        {
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < len1; i++)
            {
                temp1 += a[i];
                temp2 += b[i];
            }
            if (temp1 > temp2)
            {
                subtract(a, b);
                add(a, b);
                printf("-");
                multiply(a, b);
            }else{
                printf("-");
                subtract(b, a);
                add(a, b);
                printf("-");
                multiply(a, b);
            }
        }else
        {
            printf("-");
            subtract(b, a);
            add(a, b);
            printf("-");
            multiply(a, b);
        }
 
    }
    else if (negative1 && negative2)
    {
        if (len1 > len2)
        {
            printf("-");
            add(a, b);
            printf("-");
            subtract(a, b);
            multiply(a, b);
        }else if (len1 == len2)
        {
            int temp1 = 0, temp2 = 0;
            for (int i = 0; i < len1; i++)
            {
                temp1 += a[i];
                temp2 += b[i];
            }
            if (temp1 > temp2)
            {
                printf("-");
                add(a, b);
                printf("-");
                subtract(a, b);
                multiply(a, b);
            }else{
                printf("-");
                add(a, b);
                subtract(b, a);
                multiply(a, b);
            }
        
        }
        else
        {
            printf("-");
            add(a, b);
            subtract(b, a);
            multiply(a, b);
        }
        
    }
    

    return 0;
}

// 【測試資料一】
// 輸入：
// 4534534535995165165161651
// 99956651651651651651454535434

// 輸出：
// 99961186186187646816619697085
// 99961186186187646816619697085
// -99952117117115656486289373783
// 453256889016852581953231905042237629576284233717441534
// -99952117117115656486289373783
// 453256889016852581953231905042237629576284233717441534

// 【測試資料二】
// 輸入：
// 9999654174541651561654165415615616541654654
// -6541651654165161651651651651465146654165444

// 輸出：
// 3458002520376489910002513764150469887489210
// 3458002520376489910002513764150469887489210
// 16541305828706813213305817067080763195820098
// -65414254271969959029599286664161440719533332822203505376428354678452577994745228576376
// 16541305828706813213305817067080763195820098
// -65414254271969959029599286664161440719533332822203505376428354678452577994745228576376

// 【測試資料三】
// 輸入：
// -5614651655165165165815165616351651
// 654155105016000000651651651651651651165

// 輸出：
// 654149490364344835486485836486035299514
// 654149490364344835486485836486035299514
// -654160719667655165816817466817268002816
// -3672853043112826841527601741547006206485802931827379657819289297423823415
// -654160719667655165816817466817268002816
// -3672853043112826841527601741547006206485802931827379657819289297423823415

// 【測試資料四】
// 輸入：
// -8949849649644898999999999999999999
// -564654654654444465416546489479874987854

// 輸出：
// -564663604504094110315546489479874987853
// -564663604504094110315546489479874987853
// 564645704804794820517546489479874987855
// 5053574263129441237230267818966306202473428408593591329453510520125012146
// 564645704804794820517546489479874987855
// 5053574263129441237230267818966306202473428408593591329453510520125012146

// 【測試資料五】
// 輸入：
// -4646546546546546546546546546465489789465999
// 4646546546546546546546546546465489789465999

// 輸出：
// 0
// -9293093093093093093093093092930979578931998
// -21590394809223638052466881294956856549579606708494079665257406619876008073585577068001
