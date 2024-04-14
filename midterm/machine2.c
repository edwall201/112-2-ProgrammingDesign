#include <stdio.h>
#include <string.h>

int isVariavle(char temp[])
{
    if(temp[0] != '_')
    {
        if (temp[0] <'A' || temp[0] > 'z')
        {
            return 0;
        }
    }
    
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] != '_')
        {
            if (!(temp[i] >='0' && temp[i] <='9') && !(temp[i] >='A' && temp[i] <='z'))
            {
                return 0;
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
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        
        }
    }else if(temp[0] == '0' && strlen(temp)!=1) return 0;
    else
    {
        for (int i = 0; i < strlen(temp); i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        
        }
    }
    return 1;
}

int isFloat(char temp[])
{
    int dot_count = 0;
    if (temp[0] == '-'){
        for (int i = 0; i < strlen(temp); i++)
        {
           if (temp[i] == '.')
           {
                dot_count ++;
           }
           
        }
    }else{
        for (int i = 1; i < strlen(temp); i++)
        {
            if (temp[i] == '.')
           {
                dot_count ++;
           }
        }
    }
    if(dot_count !=1) return 0;
    else if(temp[strlen(temp)-1] == '.') return 0;
    else if(temp[0] == '.') return 0;
    else if (temp[0] == '-')
    {
        if(temp[1] == '0' && temp[2] !='.') return 0;
        for (int i = 1; i < strlen(temp); i++)
        {
            if (temp[i] != '.')
            {    if (!(temp[i] >='0' && temp[i] <='9') )
                {
                    return 0;
                }
            }
        
        }
    }else
    {
        if(temp[0] == '0' && temp[1] !='.') return 0;
        for (int i = 0; i < strlen(temp); i++)
        {
            if (temp[i] != '.')
            {    if (!(temp[i] >='0' && temp[i] <='9') )
                {
                    return 0;
                }
            }
        
        }
    }
    return 1;
}

int isFraction1(char temp[])
{
    int count = 0, position = 0;
    if(!strchr(temp, '/')) return 0;
    if(strchr(temp, '(')) return 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '/')
        {
            count++;
            position = i;
        }
    }
    if(count != 1) return 0;
    if (position == 0 || position == strlen(temp)-1) return 0;
    // printf("%d", strlen(temp)); //3
    if (temp[0] == '-')
    {
        for (int i = 1; i < position; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
        
        for (int i = position + 1; i < strlen(temp); i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
    }else
    {
        for (int i = 0; i < position; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
        for (int i = position +1 ; i < strlen(temp); i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
    }
    int a = 0, b = 0;
    if (temp[0] == '-')
    {
        a = position - 1;
        b = strlen(temp) - position - 1;
    }else{
        a = position;
        b = strlen(temp) - position - 1;
    }

    if(a > b)return 0;
    if (a == b)
    {
        if(temp[0] == '-')
        {
            for (int i = 1; i < position; i++)
            {
                if (temp[i] > temp[i+position]) return 0;
            }
        }else
        {
            for (int i = 0; i < position; i++)
            {
                if (temp[i] > temp[i + position + 1]) return 0;
                
            }
        }
    }
    
    return 1;
}

int isFraction2(char temp[])
{
    int count = 0, position = 0;
    if(!strchr(temp, '/')) return 0;
    if(strchr(temp, '(')) return 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '/')
        {
            count++;
            position = i;
        }
    }
    if(count != 1) return 0;
    if (position == 0 || position == strlen(temp)-1) return 0;
    // printf("%d", strlen(temp)); //3
    if (temp[0] == '-')
    {
        for (int i = 1; i < position; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
        
        for (int i = position + 1; i < strlen(temp); i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
    }else
    {
        for (int i = 0; i < position; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
        for (int i = position +1 ; i < strlen(temp); i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
    }
    int a = 0, b = 0;
    if (temp[0] == '-')
    {
        a = position - 1;
        b = strlen(temp) - position - 1;
    }else{
        a = position;
        b = strlen(temp) - position - 1;
    }

    return 1;
}

int isFraction3(char temp[])
{
    int count = 0, position = 0, circle1 = 0, circle2 = 0, circle_count = 0;
    if(!strchr(temp, '/')) return 0;
    if(!strchr(temp, '(')) return 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == '/')
        {
            count++;
            position = i;
        }
        if (temp[i] == '(')
        {
            circle_count++;
            circle1 = i;
        }
        if (temp[i] == ')')
        {
            circle_count++;
            circle2 = i;
        }
        
    }
    if(count != 1) return 0;
    if(circle_count != 2) return 0;
    if (circle2 - circle1 == 1) return 0;
    if (position == 0 || position == strlen(temp)-1) return 0;
    if(circle2 != strlen(temp) -1 ) return 0;
    // printf("%d", strlen(temp)); //3
    if (temp[0] == '-')
    {
        for (int i = 1; i < circle1; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
        for (int i = circle1 + 1; i < position; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }

        for (int i = position + 1; i < circle2; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
    }else
    {
        for (int i = 0; i < circle1; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
        
        for (int i = circle1 + 1; i < position; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }

        for (int i = position + 1; i < circle2; i++)
        {
            if (!(temp[i] >='0' && temp[i] <='9') )
            {
                return 0;
            }
        }
    }
    // int a = 0, b = 0;
    // if (temp[0] == '-')
    // {
    //     a = position - 1;
    //     b = strlen(temp) - position - 1;
    // }else{
    //     a = position;
    //     b = strlen(temp) - position - 1;
    // }

    return 1;
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        char temp[100];
        scanf("%s", &temp);
        if(isVariavle(temp)) printf("variable\n");
        else if(isInteger(temp)) printf("integer\n");
        else if(isFloat(temp)) printf("float\n");
        else if(isFraction1(temp)) printf("proper fraction\n");
        else if(isFraction2(temp)) printf("improper fraction\n");
        else if(isFraction3(temp)) printf("algebraic fraction\n");
        else printf("error\n");
    }
    
}