#include <stdio.h>
#include <string.h>
int isVariable(char temp[])
{
    for (int i = 0; i < strlen(temp); i++)
    {
        if(i == 0 && temp[i]!='_' && !(temp[i]>='A' && temp[i] <='z')) return 0;
        else if(temp[i] != '_' && !(temp[i]>='A' && temp[i] <='z') && !(temp[i]>='0' && temp[i] <='9')) return 0;
    }
    return 1;
}

int isInteger(char temp[])
{
    for (int i = 0; i < strlen(temp); i++)
    {
        if(i == 0 && temp[i] == '-') continue;
        else if(!(temp[i]>='0' && temp[i] <='9')) return 0;
    }
    return 1;
}

int isFloat(char temp[])
{
    int pointcount = 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if(i == 0 && temp[i] == '-') continue;
        if(temp[i] == '.' || i == strlen(temp) - 1) return 0;
        if(temp[i] == '.') pointcount++;
        else if(!(temp[i]>='0' && temp[i] <='9')) return 0;
        if(pointcount > 1 ) return 0;
    }
    return 1;
}

int isFraction1(char temp[])
{
    int frac_count = 0, frac = 0;
    if(strchr(temp,'(') || !strchr(temp, '/') || strchr(temp,'(')) return 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if(i == 0 && temp[i] == '-') continue;
        else if(temp[i] == '/') {frac_count ++; frac = i;}
        else if(!(temp[i]>='0' && temp[i] <='9')) return 0;
    }
    if(frac_count > 1 || frac == strlen(temp)-1) return 0;
    if(temp[0] == '-' && frac == 1) return 0;
    else if(frac == 0) return 0;
    if(temp[frac+1] == '0') return 0;
    int a = 0, b = 0;
    if(temp[0] == '-'){a = frac - 1; b = strlen(temp) - frac - 1;}
    else {a = frac; b = strlen(temp) - frac - 1;}
    if(a > b) return 0;
    else if(a == b)
    {
        if (temp[0] == '-')
        {
            for (int i = 1; i < frac; i++)
            {
                if (temp[i] > temp[i+frac]) return 0;
                
            }
        }else{
            for (int i = 0; i < frac; i++)
            {
                if (temp[i] > temp[i+frac+1]) return 0;
                
            }
        }
        
    }
    
    return 1;
}

int isFraction2(char temp[])
{
    int frac_count = 0, frac = 0;
    if(strchr(temp,'(') || !strchr(temp, '/') || strchr(temp,'(')) return 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if(i == 0 && temp[i] == '-') continue;
        else if(temp[i] == '/') {frac_count ++; frac = i;}
        else if(!(temp[i]>='0' && temp[i] <='9')) return 0;
    }
    if(frac_count > 1 || frac == strlen(temp)-1) return 0;
    if(temp[frac+1] == '0') return 0;
    if(temp[0] == '-' && frac == 1) return 0;
    else if(frac == 0) return 0;
    return 1;
}
int isFraction3(char temp[])
{
    int frac_count = 0, frac = 0,circle_count = 0, circle1 = 0, circle2 = 0;
    if(!strchr(temp,'(') || !strchr(temp, '/') || !strchr(temp,'(')) return 0;
    for (int i = 0; i < strlen(temp); i++)
    {
        if(i == 0 && temp[i] == '-') continue;
        if(temp[i] == '(') {circle_count ++; circle1 = i;}
        else if(temp[i] == ')') {circle_count ++; circle2 = i;}
        else if(temp[i] == '/') {frac_count ++; frac = i;}
        else if(!(temp[i]>='0' && temp[i] <='9')) return 0;
    }
    if(circle_count > 2 || frac_count > 1) return 0;
    if(!(frac < circle2 && frac > circle1)) return 0;
    if(frac == circle2 - 1) return 0;
    if(temp[frac+1] == '0') return 0;
    int a = frac - circle1 - 1, b = circle2 - frac - 1;
    if(a > b) return 0;
    else if(a == b)
    {

        for (int i = circle1 + 1; i < frac; i++)
        {
            if (temp[i] > temp[i+a+1]) return 0;
        }
    }
    
    return 1;
}
int main()
{
    int time = 0;
    scanf("%d", &time);
    for (int i = 0; i < time; i++)
    {
        char temp[100];
        scanf("%s", temp);
        if(isVariable(temp)) printf("variable\n");
        else if(isInteger(temp)) printf("integer\n");
        else if(isFloat(temp)) printf("float\n");
        else if(isFraction1(temp)) printf("proper fraction\n");
        else if(isFraction2(temp)) printf("improper fraction\n");
        else if(isFraction3(temp)) printf("algebric fraction\n");
        else printf("error\n");
    }
    
}