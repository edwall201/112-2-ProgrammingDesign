#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void formula(int x1, int y1, int x2, int y2)
{
    int m1, m2, b1, b2;
    m1 = (y1 - y2);
    m2 = (x1 - x2);
    b1 = (x2 * y1 - x1 * y2);
    b2 = (x2 - x1);
    if ((m1 < 0) && (m2 < 0)){
        m1 = m1 *-1;
        m2 = m2 *-1;
    }
    if ((b1 < 0) && (b2 <0)){
        b1 = b1 *-1;
        b2 = b2 *-1;
    }
    // printf("%d %d %d %d \n", m1, m2 , b1, b2);
    if ((m1 == 0) || (m2 ==0)){
        if ((b1 == 0) || (b2 ==0)){
            printf("y\n");
        }else if((b1 % b2 == 0) && (b1 / b2 == 1))
        {
            printf("y = 1\n");
        }else if((b1 % b2 == 0) && (b1 / b2 == -1))
        {
            printf("y = -1\n");
        }
        else if((b1 % b2 == 0))
        {
            printf("y = %d\n", b1/b2);
        }else{
            int gcd1 = gcd(b1, b2);
            if (gcd1 < 0)
            {
                gcd1 = gcd1 * -1;
            }
            b1 = b1 / gcd1;
            b2 = b2 / gcd1;
            if (b1 < 0){
                printf("y = -%d/%d\n", -1*b1, b2);
            }else if (b2 < 0){
                printf("y = -%d/%d\n", b1, -1*b2);
            }else{
                printf("y = %d/%d\n", b1, b2); 
            }
        }
    }else if((m1 % m2) == 0){
        if((m1 / m2) == 1){
            if ((b1 == 0) || (b2 ==0)){
                printf("y = x\n");
            }else if((b1 % b2 == 0) && (b1 / b2 == 1))
            {
                printf("y = x + 1\n");
            }else if((b1 % b2 == 0) && (b1 / b2 == -1))
            {
                printf("y = x - 1\n");
            }
            else if((b1 % b2 == 0))
            {
                if (b1 < 0){
                    printf("y = x - %d\n", (-1*b1)/b2);
                }else if (b2 < 0){
                    printf("y = x - %d\n", b1/(-1*b2));
                }else{
                   printf("y = x + %d\n", b1/b2); 
                }
                
            }else{
                int gcd1 = gcd(b1, b2);
                if (gcd1 < 0)
                {
                    gcd1 = gcd1 * -1;
                }
                b1 = b1 / gcd1;
                b2 = b2 / gcd1;
                if (b1 < 0){
                    printf("y = x - %d/%d\n", -1*b1, b2);
                }else if (b2 < 0){
                    printf("y = x - %d/%d\n", b1, -1*b2);
                }else{
                    printf("y = x + %d/%d\n", b1, b2); 
                }
            }
        }else if((m1 / m2) == -1){
            if ((b1 == 0) || (b2 ==0)){
                printf("y = -x\n");
            }else if((b1 % b2 == 0) && (b1 / b2 == 1))
            {
                printf("y = -x + 1\n");
            }else if((b1 % b2 == 0) && (b1 / b2 == -1))
            {
                printf("y = -x - 1\n");
            }
            else if((b1 % b2 == 0))
            {
                if (b1 < 0){
                    printf("y = -x - %d\n", (-1*b1)/b2);
                }else if (b2 < 0){
                    printf("y = -x - %d\n", b1/(-1*b2));
                }else{
                   printf("y = -x + %d\n", b1/b2); 
                }
            }else{
                int gcd1 = gcd(b1, b2);
                if (gcd1 < 0)
                {
                    gcd1 = gcd1 * -1;
                }
                b1 = b1 / gcd1;
                b2 = b2 / gcd1;
                if (b1 < 0){
                    printf("y = -x - %d/%d\n", -1*b1, b2);
                }else if (b2 < 0){
                    printf("y = -x - %d/%d\n", b1, -1*b2);
                }else{
                    printf("y = x + %d/%d\n", b1, b2); 
                }
            }
        }else{
            if ((b1 == 0) || (b2 ==0)){
                printf("y = %dx\n", m1/m2);
            }else if((b1 % b2 == 0) && (b1 / b2 == 1))
            {
                printf("y = %dx + 1\n", m1/m2);
            }else if((b1 % b2 == 0) && (b1 / b2 == -1))
            {
                printf("y = %dx - 1\n",m1/m2);
            }
            else if((b1 % b2 == 0))
            {
                if (b1 < 0){
                    printf("y = %dx - %d\n",m1/m2, (-1*b1)/b2);
                }else if (b2 < 0){
                    printf("y = %dx - %d\n",m1/m2, b1/(-1*b2));
                }else{
                   printf("y = %dx + %d\n",m1/m2, b1/b2); 
                }
            }else{
                int gcd1 = gcd(b1, b2);
                if (gcd1 < 0)
                {
                    gcd1 = gcd1 * -1;
                }
                b1 = b1 / gcd1;
                b2 = b2 / gcd1;
                if (b1 < 0){
                    printf("y = %dx - %d/%d\n",m1/m2, -1*b1, b2);
                }else if (b2 < 0){
                    printf("y = %dx - %d/%d\n",m1/m2, b1, -1*b2);
                }else{
                    printf("y = %dx + %d/%d\n",m1/m2, b1, b2); 
                }
            }
        }        
    }else{
        if ((b1 == 0) || (b2 ==0)){
            int gcd1 = gcd(m1, m2);
            if (gcd1 < 0)
            {
                gcd1 = gcd1 * -1;
            }
            m1 = m1 / gcd1;
            m2 = m2 / gcd1;
            if (m2 < 0)
            {
                printf("y = -%d/%dx\n", m1, -1*m2);
            }else
            {
                printf("y = %d/%dx\n", m1, m2);
            }
            
            
        }else if((b1 % b2 == 0) && (b1 / b2 == 1))
        {
            int gcd1 = gcd(m1, m2);
            if (gcd1 < 0)
            {
                gcd1 = gcd1 * -1;
            }
            m1 = m1 / gcd1;
            m2 = m2 / gcd1;
            if (m2 < 0)
            {
                printf("y = -%d/%dx + 1\n", m1, -1*m2);
            }else
            {
                printf("y = %d/%dx + 1\n", m1, m2);
            }
        }else if((b1 % b2 == 0) && (b1 / b2 == -1))
        {
            int gcd1 = gcd(m1, m2);
            if (gcd1 < 0)
            {
                gcd1 = gcd1 * -1;
            }
            m1 = m1 / gcd1;
            m2 = m2 / gcd1;
            if (m2 < 0)
            {
                printf("y = -%d/%dx - 1\n", m1, -1*m2);
            }else
            {
                printf("y = %d/%dx - 1\n", m1, m2);
            }
        }
        else if((b1 % b2 == 0))
        {
            int gcd1 = gcd(m1, m2);
            if (gcd1 < 0)
            {
                gcd1 = gcd1 * -1;
            }
            m1 = m1 / gcd1;
            m2 = m2 / gcd1;
            if( b1 / b1 < 0){
                if (m2 < 0)
                {
                    printf("y = -%d/%dx - %d\n", m1, -1*m2, -1* (b1/b2));
                }else
                {
                    printf("y = %d/%dx - %d\n", m1, m2, -1* (b1/b2));
                }
            }else{
                if (m2 < 0)
                {
                    printf("y = -%d/%dx + %d\n", m1, -1*m2, (b1/b2));
                }else
                {
                    printf("y = %d/%dx + %d\n", m1, m2, (b1/b2));
                }
            }
        }else{
            int gcd1 = gcd(m1, m2);
            if (gcd1 < 0)
            {
                gcd1 = gcd1 * -1;
            }
            m1 = m1 / gcd1;
            m2 = m2 / gcd1;

            int gcd2 = gcd(b1, b2);
            if (gcd2 < 0)
            {
                gcd2 = gcd2 * -1;
            }
            b1 = b1 / gcd2;
            b2 = b2 / gcd2;
            if(m2 < 0){
                if(b1 < 0){
                    printf("y = -%d/%dx - %d/%d\n", m1, -1*m2, -1*b1, b2);
                }else if(b2 < 0){
                    printf("y = -%d/%dx - %d/%d\n", m1, -1*m2, b1, -1*b2);
                }else{
                    printf("y = -%d/%dx + %d/%d\n", m1, -1*m2, b1, b2);
                }
            }else{
                if(b1 < 0){
                    printf("y = %d/%dx - %d/%d\n", m1, m2, -1*b1, b2);
                }else if(b2 < 0){
                    printf("y = %d/%dx - %d/%d\n", m1, m2, b1, -1*b2);
                }else{
                    printf("y = %d/%dx + %d/%d\n", m1, m2, b1, b2);
                }
            }
        }
    }

}

int main()
{

    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d" ,&x1, &y1, &x2, &y2);
        formula(x1, y1, x2, y2);
    } 
}

