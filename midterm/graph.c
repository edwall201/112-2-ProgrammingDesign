#include <stdio.h>

int first_1(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        printf("#");
    }
    for (int i = a-b; i > 0; i--)
    {
        printf("%d", i);
    }
    
    
    return 0;
}
int first_2(int a, int b)
{
    for (int i = 2; i<= a-b; i++)
    {
        if(i != 1) printf("%d", i);
    }
    for (int i = 0; i < b; i++)
    {
        printf("#");
    }
    

    return 0;
}

int first(int a){
    for(int i = a -1; i > 0; i--){
        first_1(a,i);
        first_2(a,i);
        printf("\n");
    }
    for (int i = a; i > 0; i--)
    {
        printf("%d", i);
    }
    for (int i = 2; i <= a; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    for(int i = 1; i < a; i++){
        first_1(a,i);
        first_2(a,i);
        printf("\n");
    }
    
    return 0;
}

int second_1(int a, int b)
{
    for (int i = 1; i <= b+1 ; i++)
    {
        printf("%d", i);
    }
    for (int i = a-b -1; i > 0; i--)
    {
        printf("#");
    }
    
    
    return 0;
}

int second_2(int a, int b)
{
    for (int i = b; i >0 ; i--)
    {
        printf("%d", i);
    }
    for (int i = a-b; i > 0; i--)
    {
        printf("#");
    }
    
    
    return 0;
}
int second(int a)
{
    for (int i = 0; i < a; i++)
    {
        second_1(a, i);
        printf("\n");
    }
    for (int i = a; i > 0; i--)
    {
        second_2(a, i);
        printf("\n");
    }
    
    return 0;
}

int third_1(int a, int b, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("#");
    }
    for (int i = 1; i <= b; i++)
    {
        printf("%d",i);
    }
    for (int i = b-1; i > 0; i--)
    {
        printf("%d",i);
    }
    
    
    
    return 0;
}

int third(int a){
    int count = a + (a-1) -1;
    for (int i = 1; i < a; i++)
    {
        third_1(a, i, count);
        count-=2;
        printf("\n");
    }
    for (int i = 1; i <= a; i++)
    {
        printf("%d", i);
    }
    for (int i = a-1; i > 0; i--)
    {
        printf("%d", i);
    }
    printf("\n");
    
    
    
    return 0;
}

int forth_1(int a, int b)
{
    for(int i = 0; i < b ;i++)
    {
        printf("#");
    }
    if ((a - b) % 2 ==1)
    {
        for (int i = 1; i <= a; i++)
        {
            printf("%d", i);
        }
        
    }else{
        for (int i = a; i > 0; i--)
        {
            printf("%d", i);
        }
    }
    if (a - b - 1 >0)
    {
        for(int i = a - b - 1; i > 0 ;i--)
        {
            printf("#");
        }
    }
    
    
    return 0;
}

int forth(int a)
{
    for (int i = a-1; i > 0; i--)
    {
        forth_1(a, i);
        printf("\n");
    }
    return 0;
}
int main()
{
    int a = 0, b= 0;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a == 1) first(b);
    else if(a ==2) second(b);
    else if( a == 3) third(b);
    else if( a == 4) forth(b);
}