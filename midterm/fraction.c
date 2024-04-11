#include <stdio.h>
#include <string.h>

int gcd(int frac, int base){
    if (base == 0)
    {
        return frac;
    }
    return gcd(base, frac % base);
    
}
int add(int *num1, int *num11, int *num2, int *num22)
{
    int base = *num11 * *num22;
    int frac = *num1 * *num22 + *num2 * *num11;
    int temp = gcd(frac, base);
    if (temp < 0) temp = -temp;
    if (base < 0)
    {
        base = -base;
        frac = -frac;
    }
    
    if(temp != 1){
        frac = frac / temp;
        base = base / temp;
    }
    if (frac / base == 0) printf("%d/%d\n", frac, base);
    else if (frac / base < 0)
    {
        printf("%d(%d/%d)\n",frac/base, -(frac - (frac/base) * base), base);
    }else
    {
        printf("%d(%d/%d)\n",frac/base, frac - (frac/base) * base, base);
    }
    return 0;
}
int minus(int *num1, int *num11, int *num2, int *num22)
{
    int base = *num11 * *num22;
    int frac = *num1 * *num22 - *num2 * *num11;
    int temp = gcd(frac, base);
    if (base < 0)
    {
        base = -base;
        frac = -frac;
    }
    if(temp < 0) temp = -temp;
    
    if(temp != 1){
        frac = frac / temp;
        base = base / temp;
    }
    if (frac / base == 0) printf("%d/%d\n", frac, base);
    else if (frac / base < 0)
    {
        printf("%d(%d/%d)\n",frac/base, (frac/base) * base - frac, base);
    }else
    {
        printf("%d(%d/%d)\n",frac/base, frac - (frac/base) * base, base);
    }
    

    return 0;
}

int mutiple(int *num1, int *num11, int *num2, int *num22)
{
    int base = *num11 * *num22;
    int frac = *num1 * *num2;
    int temp = gcd(frac, base);
    if (base < 0)
    {
        base = -base;
        frac = -frac;
    }
    if(temp < 0) temp = -temp;
    
    if(temp != 1){
        frac = frac / temp;
        base = base / temp;
    }
    if (frac / base == 0) printf("%d/%d\n", frac, base);
    else if (frac / base < 0)
    {
        printf("%d(%d/%d)\n",frac/base, (frac/base) * base - frac, base);
    }else
    {
        printf("%d(%d/%d)\n",frac/base, frac - (frac/base) * base, base);
    }
    

    return 0;
}



int main()
{
    char frac1[100], frac2[100];
    int num1, num11, den1, den2, num2, num22;
    scanf("%s", frac1);
    scanf("%s", frac2);

    if (strchr(frac1, '('))
    {
        sscanf(frac1, "%d(%d/%d)",&den1, &num1, &num11);
        if (den1 < 0)
        {
            num1 = num11 * den1 - num1;
        }
        else num1 += num11 * den1;
    }
    else sscanf(frac1, "%d/%d", &num1, &num11);

    if (strchr(frac2, '(')) {
        sscanf(frac2, "%d(%d/%d)",&den2, &num2, &num22);
        if (den2 < 0)
        {
            num2 = num22 * den2 - num2;
        }
        else num2 += num22 * den2;
    }
    else sscanf(frac2, "%d/%d", &num2, &num22);
    
    if(num11 == 0 || num22 == 0)
    {
        printf("error\n");
    }else
    {
        add(&num1, &num11, &num2, &num22);
        minus(&num1, &num11, &num2, &num22);
        mutiple(&num1, &num11, &num2, &num22);
        mutiple(&num1, &num11, &num22, &num2);
    }
    // printf("%d %d %d \n", num1, num11, den1);

    
}