
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, judge, temp, ans, ans2;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    judge = pow(b, 2) - 4 * a * c;
    if (judge < 0)
    {
        temp = ( -b ) / ( 2 * a ); 
        ans =  ( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ));
        ans2 = ( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ));
        printf("%.1f+%.1fi\n", temp, ans);
        printf("%.1f-%.1fi\n", temp, ans2);
    }else
    {
        ans = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        ans2 = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        if (ans == -0.0)
        {
            ans = 0.0;
        }
        if (ans2 == -0.0)
        {
            ans2 = 0.0;
        }
        printf("%.1f\n", ans);
        printf("%.1f\n", ans2);
    }
    


    return 0;
}
