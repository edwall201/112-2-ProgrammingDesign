#include <stdio.h>
#include <string.h>

int main()
{
    char frac1[100], frac2[100];
    int num1, num11, den1, den2, num2, num22;
    scanf("%s", frac1);
    // scanf("%s", frac2);
    if (strchr(frac1, '('))
    {
        if (strchr(frac1, '-'))
        {
            sscanf(frac1, "%d(%d/%d)",&den1, &num1, &num11);
        }else
        {
            sscanf(frac1, "%d(%d/%d)",&den1, &num1, &num11);
        }
    }else if(strchr(frac1, '-')){
        sscanf(frac1, "-%d/%d", &num1, &num11);
    }else{
        sscanf(frac1, "%d/%d", &num1, &num11);
    }
    printf("%d %d %d \n", num1, num11, den1);

    
}