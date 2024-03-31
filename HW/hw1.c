#include <stdio.h>
#include <math.h>

int main()
{
    float h, w;
    float bmi;
    scanf("%f", &w);
    scanf("%f", &h);
    bmi = w / pow((h / 100), 2);
    printf("%.1f\n", bmi);
}
