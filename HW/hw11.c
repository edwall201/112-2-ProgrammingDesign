#include <stdio.h>
#include <stdlib.h>

void decimalToBase(int N, long long decimal)
{
    if (decimal ==0)
    {
        return;
    }
    decimalToBase(N, decimal / N);
    if(decimal % N >= 10)
    {
        printf("%c",'A'+(decimal % N) - 10);
    }else
    {
        printf("%d", decimal % N);
    }
}
    

int main()
{
    int N, M;
    char input[11];
    scanf("%d", &N);
    scanf("%s", input);
    long long decimal = strtoll(input, NULL, N);

    scanf("%d", &M);
    if (decimal == 0)
    {
        printf("0");
        return 0;
    }else{
        decimalToBase(M, decimal);
    }
}
