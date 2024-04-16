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
int add(int *frac1, int *frac11, int *frac2, int *frac22)
{
    int base = *frac11 * *frac22;
    int frac = *frac1 * *frac22 + *frac2 * *frac11;
    int temp = gcd(frac, base);
    if(temp < 0) temp *= -1;
    frac /= temp;
    base /= temp;
    if(frac % base == 0) printf("%d\n", frac/base);
    else if(frac / base > 0)
    {
        printf("%d(%d/%d)\n",frac/base, frac - (frac/base)*base, base);
    }
    else if(frac / base < 0)
    {
        printf("%d(%d/%d)\n",frac/base, -(frac - (frac/base)*base), base);
    }
    else printf("%d/%d\n", frac, base);

    return 0;
}

int minus(int *frac1, int *frac11, int *frac2, int *frac22)
{
    int base = *frac11 * *frac22;
    int frac = *frac1 * *frac22 - *frac2 * *frac11;
    int temp = gcd(frac, base);
    if(temp < 0) temp *= -1;
    frac /= temp;
    base /= temp;
    if(frac % base == 0) printf("%d\n", frac/base);
    else if(frac / base > 0)
    {
        printf("%d(%d/%d)\n",frac/base, frac - (frac/base)*base, base);
    }
    else if(frac / base < 0)
    {
        printf("%d(%d/%d)\n",frac/base, -(frac - (frac/base)*base), base);
    }
    else printf("%d/%d\n", frac, base);

    return 0;
}

int mutiple(int *frac1, int *frac11, int *frac2, int *frac22)
{
    int base = *frac11 * *frac22;
    int frac = *frac1 * *frac2 ;
    int temp = gcd(frac, base);
    if(temp < 0) temp *= -1;
    frac /= temp;
    base /= temp;
    if(frac % base == 0) printf("%d\n", frac/base);
    else if(frac / base > 0)
    {
        printf("%d(%d/%d)\n",frac/base, frac - (frac/base)*base, base);
    }
    else if(frac / base < 0)
    {
        printf("%d(%d/%d)\n",frac/base, -(frac - (frac/base)*base), base);
    }
    else printf("%d/%d\n", frac, base);

    return 0;
}
int main()
{
    char a[50], b[50];
    int den1 = 0, frac1 = 0, frac11 = 0, den2 = 0, frac2 = 0, frac22 = 0;
    scanf("%s", a);
    scanf("%s", b);
    if (strchr(a, '(')) {
        sscanf(a, "%d(%d/%d)", &den1, &frac1, &frac11);
        if(den1 < 0) frac1 = den1 * frac11 - frac1;
        else frac1 += den1 * frac11;
    }
    else{
        sscanf(a, "%d/%d", &frac1, &frac11);
        frac1 += den1 * frac11;
    }
   
    if (strchr(b, '(')) 
    { 
        sscanf(b, "%d(%d/%d)", &den2, &frac2, &frac22);
        if(den2 < 0) frac2 = den2 * frac22 - frac2;
        else frac2 += den2 * frac22;
    }
    else 
    {
        sscanf(b, "%d/%d", &frac2, &frac22);
        frac2 += den2 * frac22;
    }
    // printf("%d %d\n", frac1,frac11);
    // printf("%d %d", frac2,frac22);
    if(frac22== 0 || frac11 == 0) printf("error\n");
    else
    {
        add(&frac1, &frac11, &frac2, &frac22);
        minus(&frac1, &frac11, &frac2, &frac22);
        mutiple(&frac1, &frac11, &frac2, &frac22);
        if(frac2 < 0 && frac22 > 0) {frac22 *= -1; frac2 *= -1;}
        mutiple(&frac1, &frac11, &frac22, &frac2);
    }

    // printf("%d %d\n", frac1,frac11);
    // printf("%d %d", frac2,frac22);
    
    
}