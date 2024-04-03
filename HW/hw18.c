#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void print(int a[], int n) {
    for (int i=0; i<n; i++)
    printf("%d ", a[i]);
    printf("\n");
}

int getMinIndex(int d[], int left, int right) {
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++) {
    if (d[i]<d[minIndex]) minIndex=i;
    }
    return minIndex;
}

void selectSort(int d[], int n) {
    int i=0, index=0, select_compare = 0, select_exchange = 0;
    printf("%d ", n * (n-1)/2);
    for (i=0; i<n; i++) {
        index = getMinIndex(d, i, n);
        if (index != i)
        {
            select_exchange++;
        }
        
        SWAP(d[i], d[index]);
    }
    printf("%d ", select_exchange*3);
    // print(d, n);  
    printf("\n");
}



void insertionSort(int a[], int n) {
    int target = 0, i = 0, j = 0, insert_compare = 0, insert_exchange = 0;
    for (i = 1; i < n; i++) {
        target = a[i];
        insert_exchange++;
        for (j = i; j >= 0; j--) {
            if (j == 0)
            {
                insert_compare++;
                break;
            }
            else if (j >0) {
                insert_compare+=2;
                if (j == 0 || a[j-1] <= target) {
                    break;
                }
            }
            a[j] = a[j-1];
            insert_exchange++;
        }
        a[j] = target;
        insert_exchange++;
    }
    // print(a, n);
    printf("%d ", insert_compare);
    printf("%d\n", insert_exchange);
}

int main() {
    int num = 0;
    scanf("%d", &num);
    int *a = (int *)malloc(num *sizeof(int));
    int *b = (int *)malloc(num *sizeof(int));// reload
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        // printf("%d\n", a[i]);
    }
    selectSort(a,num);
    insertionSort(b, num);
    

    // int a[] = {5, 3, 8, 23, 15};
    // insertionSort(a, 5);

    return 0;
}