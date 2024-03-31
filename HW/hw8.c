#include <stdio.h>
#include <math.h>
// gray code

void GrayCode(int n, int k){
    if (n == 1){
        printf("%d", k);
    }else if (k < pow(2, n-1)){
        printf("%d",0);
        GrayCode(n-1, k);
    }else{
        printf("%d",1);
        GrayCode(n-1, pow(2, n) - k - 1);
    }
}

int main()
{
    int n = 0, k = 0, temp = 0;\
    scanf("%d %d", &n, &k);
    while (n != -1){
        GrayCode(n, k);
        printf("\n");
        scanf("%d", &n);
        if (n == -1){
            break;
        }
        scanf("%d", &k);
    }
}
    