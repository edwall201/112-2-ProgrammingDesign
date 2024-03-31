#include <stdio.h>
#include <math.h>

int toDecimal(long binaryNumber)
{
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0)
    {
        remainder = binaryNumber % 10;
        decimalNumber += remainder * pow(2, i);
        binaryNumber /= 10;
        i++;
    }
    return decimalNumber;
}

int R(int r)
{
    if ((r == 0) || (r == 1))
    {
        return 1;
    }else if (r % 2 == 0){
        return 1 + R(r/2);
    }else{
        return 1 + R((r+1)/2);
    }
}

int T(int t)
{
    int count = 0;
    for (int i = 1; i < t +1; i++)
    {
       count += (R(i) - 1);
    }
    return count;
}

void toBinary(int decimalNumber)
{
    int ans[14] = {0};
    long binaryNumber = 0;
    int remainder, i = 0;
    while (decimalNumber != 0)
    {
        ans[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }
    for (int j = 13; j > -1; j--)
    {
    
        printf("%d", ans[j]);
    }
    printf("\n");
}

int main()
{
    long binaryNumber;
    scanf("%ld", &binaryNumber);
    int t = toDecimal(binaryNumber);
    toBinary(T(t));
    scanf("%ld", &binaryNumber);
    // 讀取中間的0分隔資料
    while (binaryNumber == 0)
    {
        scanf("%ld", &binaryNumber);
        if (binaryNumber == -1)
        {
            break;
        }
        int t = toDecimal(binaryNumber);
        toBinary(T(t));
        scanf("%ld", &binaryNumber);
    }

    // 如果不是0，繼續處理下一個測試案例
    // 如果是-1，則結束迴圈
    // if (binaryNumber != -1)
    // {
    //     int t = toDecimal(binaryNumber);
    //     toBinary(T(t));
    // }
}
    
    

