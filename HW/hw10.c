#include <stdio.h>
#include <string.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void simplify(int num, int den)
{
    if (num == 0 || den == 0)
    {
        printf("0\n");
        return;
    }else
    {
        int gcd1 = gcd(num, den);
        if (gcd1 < 0)
        {
            gcd1 = gcd1 * -1;
        }
        num = num / gcd1;
        den = den / gcd1;
        if (num < 0)
        {
            if (num * - 1 > den)
            {
                printf("%d(%d/%d)\n", num / den, (num % den) * -1, den);
            }
            else
            {
                printf("%d/%d\n", num , den);
            }
        }else if (num > den)
        {
            printf("%d(%d/%d)\n", num / den, num % den, den);
        }
        else
        {
            printf("%d/%d\n", num / gcd1, den / gcd1);
        }
    }
    
}

void count(int num1, int den1, int num2, int den2, char operation)
{
    int num3, den3;

    if(operation == '+'){
        num3 = (num1 * den2) + (num2 * den1);
        den3 = den1 * den2;
    }else if(operation == '-'){
        num3 = (num1 * den2) - (num2 * den1);
        den3 = den1 * den2;
    }else if(operation == '*'){
        num3 = num1 * num2;
        den3 = den1 * den2;
    }else if(operation == '/'){
        num3 = num1 * den2;
        den3 = den1 * num2;
    }
    if (den1 == 0 || den2 == 0 || den3 == 0)
    {
        printf("error\n");
    }else{
        simplify(num3, den3);
    }
}

int main(){
    char operation;
    char check = 'y';

    while (check == 'y')
    {
        char fraction1[100], fraction2[100];
        int num1, num1_1, den1;
        scanf("%s", &fraction1);
        if (strchr(fraction1, '('))
        {
            if (strchr(fraction1, '-')){
                sscanf(fraction1, "-%d(%d/%d)", &num1, &num1_1, &den1);
                num1_1 = num1_1 + (num1 * den1);
                num1_1 = num1_1 * -1;
            }else{
           sscanf(fraction1, "%d(%d/%d)", &num1, &num1_1, &den1);
           num1_1 = num1_1 + (num1 * den1);                
            }
        }else
        {
            if (strchr(fraction1, '-')){
                sscanf(fraction1, "-%d/%d", &num1_1, &den1);
                num1_1 = num1_1 * -1;
            }else{
            sscanf(fraction1, "%d/%d", &num1_1, &den1);
            }
        }

        scanf("%s", &operation);
        int num2, num2_1, den2;
        scanf("%s", fraction2);
        if (strchr(fraction2, '('))
        {
            if (strchr(fraction2, '-')){   
                sscanf(fraction2, "-%d(%d/%d)", &num2, &num2_1, &den2);
                num2_1 = num2_1 + (num2 * den2);
                num2_1 = num2_1 * -1;
            }else{
                sscanf(fraction2, "%d(%d/%d)", &num2, &num2_1, &den2);
                num2_1 = num2_1 + (num2 * den2);
            }
        }else
        {
            if (strchr(fraction2, '-')){
                sscanf(fraction2, "-%d/%d", &num2_1, &den2);
                num2_1 = num2_1 * -1;
            }else{
                sscanf(fraction2, "%d/%d", &num2_1, &den2);
            }
        }
        count(num1_1, den1, num2_1, den2, operation);
        scanf("%s", &check);
    }
    

}