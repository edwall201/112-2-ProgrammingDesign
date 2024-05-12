#include <stdio.h>
#include <string.h>

int isVariable(char temp[])
{
    if (temp[0] != '_' )
    { 
        if ((temp[0] > 'z') || (temp[0] < 'A')) return 0;
    }
    for (int i = 1; i < strlen(temp); i++)
    {
        if (temp[i]!= '_')
        {
            if (temp[i] > 'z' || temp[i] < 'A')
            {
               if (!(temp[i] >= '0' && temp[i] <= '9'))
                {
                    return 0;
                }
            }
            
    
        }
        
    }
    
    return 1;
}

int isInteger(char temp[])
{
    if (temp[0] == '-')
    {
       for (int i = 1; i < strlen(temp); i++)
        {
            if (temp[i] > '9' || temp[i] < '0')
            {
                return 0;
            }
            
        }
    }else
    {
        for (int i = 0; i < strlen(temp); i++)
        {
            if (temp[i] > '9' || temp[i] < '0')
            {
                return 0;
            }
            
        }
    }
    return 1;
    
    
    
}

int isFloat(char temp[])
{
    int point = 0, pointCount = 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '.')
        {
            point = i;
            pointCount ++;
        }
    }
    if (pointCount > 1 || pointCount ==0 ) return 0;
    if(point == 0 || point == strlen(temp)-1) return 0;
    if (temp[0] == '-' && temp[1] == '0' && temp[2] != '.') return 0;
    
    for (int i = 0; i < strlen(temp); i++)
    {
        if (i == 0 && temp[i]=='-')
        {
            continue;
        }else if(temp[i] != '.')
        {   
            if (temp[i] > '9' || temp[i] < '0') return 0;
        }
        
    }
    return 1;

    
    
}

int isFraction1(char temp[])
{
    int frac = 0, fracCount = 0;
    for(int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '/')
        {
            frac = i;
            fracCount ++;
        }
        
    }
    if (fracCount == 0 || fracCount > 1) return 0;
    if (strchr(temp, '(')) return 0;
    
    for (int i = 0; i < strlen(temp); i++)
    {
        if (i == 0 && temp[i]=='-')
        {
            continue;
        }
        else if(temp[i] != '/')
        {   
            if (temp[i] > '9' || temp[i] < '0') return 0;
        }
    }
    return 1;
}

int isFraction2(char temp[])
{
    int frac = 0, fracCount = 0, circle1 = 0, circle1_count = 0, circle2_count = 0, circle2 = 0;
    for(int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '/')
        {
            frac = i;
            fracCount ++;
        }
        if (temp[i] == '(')
        {
            circle1 = i;
            circle1_count ++;
        }
        if (temp[i] == ')')
        {
            circle2 = i;
            circle2_count++;
        }
        
        
    }
    if (fracCount == 0 || fracCount > 1) return 0;
    if (circle1_count != 1 || circle2_count != 1) return 0;
    if(circle2 != strlen(temp) - 1) return 0;
    for (int i = 0; i < circle1; i++)
    {
        if (i == 0 && temp[i]=='-')
        {
            continue;
        }
        if (temp[i] > '9' || temp[i] < '0') return 0;
    }
    for (int i = circle1+1; i < frac; i++)
    {
        if (temp[i] > '9' || temp[i] < '0') return 0;
    }
    for (int i = frac + 1; i < circle2; i++)
    {
        if (temp[i] > '9' || temp[i] < '0') return 0;
    }


    return 1;
}
int main()
{
    int num = 0;
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++)
    {
        char temp[50];
        scanf("%s", temp);
        if (isVariable(temp))    printf("variable\n");
        else if(isInteger(temp)) printf("integer\n");
        else if(isFloat(temp))   printf("float\n");
        else if(isFraction1(temp)) printf("improper fraction\n");
        else if(isFraction2(temp)) printf("algebraic fraction\n");
        else printf("error\n");
    }
   
    
}