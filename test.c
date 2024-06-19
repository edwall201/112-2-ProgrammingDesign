#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
    char *word;
    int count;
}wordEntry;

void insertBefore(char *arr[], char p[], char q[],int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(arr[i],p) == 0) printf("%s ",q);
        printf("%s ",arr[i]);
    }
    printf("\n");
    
}
void replace(char *arr[], char p[], char q[],int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(arr[i],p) == 0) printf("%s ",q);
        else printf("%s ",arr[i]);
    }
    printf("\n");
    
}
void delete(char *arr[], char p[],int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(arr[i],p) == 0) continue;
        else printf("%s ",arr[i]);
    }
    printf("\n");
}

void lowFrquency(char *arr[], int totalcount, int n){
    wordEntry newArr[1000] = {0};
    int newCount = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < newCount; j++)
        {
            if(strcmp(arr[i], newArr[j].word) == 0){
                found = 1;
                newArr[j].count ++;
                break;
            }
        }
        if(!found){
            newArr[newCount].word = arr[i];
            newArr[newCount].count =1;
            newCount +=1;
        }      
    }
    for (int i = 0; i < totalcount; i++)
    {
        for (int j = 0; j < newCount; j++)
        {
            if(strcmp(arr[i], newArr[j].word) == 0 && newArr[j].count >= n){
                printf("%s ", arr[i]);
                break;
            }
        }   
    }
    printf("\n");
}

int compare(const void *a, const void *b){
    wordEntry *A = (wordEntry *)a;
    wordEntry *B = (wordEntry *)b;
    if(A->count != B->count) return A->count - B->count;
    return strcmp(A->word, B->word);
}

void Frquency(char *arr[], int totalcount){
    wordEntry newArr[1000] = {0};
    int newCount = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < newCount; j++)
        {
            if(strcmp(arr[i], newArr[j].word) == 0){
                found = 1;
                newArr[j].count ++;
                break;
            }
        }
        if(!found){
            newArr[newCount].word = arr[i];
            newArr[newCount].count =1;
            newCount +=1;
        }      
    }
    qsort(newArr, newCount, sizeof(wordEntry), compare);
    for (int i = 0; i < 3; i++)
    {
        printf("%s:%d\n", newArr[i].word, newArr[i].count);
    
    }

}

int main(){
    int command;
    char article[1000], p[100], q[100];
    fgets(article, sizeof(article), stdin);
    scanf("%s", p);
    scanf("%s",q);
    scanf("%d", &command);
    article[strcspn(article,"\n")] = 0;
    char *arr[1000];
    char *token = strtok(article," ");
    int totalcount=0;
    while (token!= NULL)
    {
        arr[totalcount++] = token;
        token = strtok(NULL," ");
    }
    if(command ==1) insertBefore(arr, p, q, totalcount);
    if(command ==2) replace(arr, p, q, totalcount);
    if(command ==3) delete(arr, p, totalcount);
    if (command == 4)
    {
        int n;
        scanf("%d", &n);
        lowFrquency(arr, totalcount, n);
    }
    else if(command == 5) Frquency(arr, totalcount);
    
}