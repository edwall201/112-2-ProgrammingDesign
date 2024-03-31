#include <stdio.h>

int main()
{
    int num = 0, count = 0;
    scanf("%d", &num);
    int list[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&list[i]);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (list[i] > list[j])
            {
                count++;
            }
            
        }
    }
    printf("%d\n", count);
    
    
}