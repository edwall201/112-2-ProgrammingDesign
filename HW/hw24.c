#include <stdio.h>
#include <string.h>

typedef struct students_s
{
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &s[i].name);
        scanf("%d", &s[i].score);
    }
}

void getHigh(student_t s[], int n, char name[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i].score > max)
        {
            max = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

int getAverage(student_t s[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i].score;
    }
    return sum/n;    
}

int main()
{
    int student_num = 0;
    scanf("%d", &student_num);
    student_t students[student_num];
    char name[50]; // Define name
    input(students, student_num);
    getHigh(students, student_num, name);
    printf("%s\n", name); // Print the name of the student with the highest score
    printf("%d\n", getAverage(students, student_num));
    return 0; 
}