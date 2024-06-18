#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char *words;
    int count;
}WordEntry;

void insertBefore(char *arr[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(arr[i],p) == 0) printf("%s ",q);
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void replace(char *arr[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(arr[i],p) == 0) printf("%s ",q);
        else printf("%s ", arr[i]);
    }
    printf("\n");
}
void delete(char *arr[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(arr[i],p) != 0) printf("%s ", arr[i]);
    }
    printf("\n");
}
void lowFrequency(char *arr[], int totalcount, int n){
    WordEntry worldentry[1000];
    int newcount = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < newcount; j++)
        {
           if(strcmp(arr[i], worldentry[j].words) == 0){
            worldentry[j].count ++;
            found =1;
           }
        }
        if(! found){
            worldentry[newcount].words = arr[i];
            worldentry[newcount].count += 1;
            newcount += 1;
        }
    }
    for (int i = 0; i < totalcount; i++)
    {
        for (int j = 0; j < newcount; j++)
        {
            if(strcmp(arr[i], worldentry[j].words) == 0 && worldentry[j].count >= n){
                printf("%s ", arr[i]);
                break;
            }
        }
    }
    printf("\n");
}
int compare(const void *a, const void *b){
    WordEntry *A = (WordEntry *)a;
    WordEntry *B = (WordEntry *)b;
    if(A->count != B->count) return A->count - B->count;
    else return strcmp(A->words, B->words);
}
void frequency(char *arr[], int totalcount){
    WordEntry worldentry[1000];
    int newcount = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < newcount; j++)
        {
           if(strcmp(arr[i], worldentry[j].words) == 0){
            worldentry[j].count ++;
            found =1;
           }
        }
        if(! found){
            worldentry[newcount].words = arr[i];
            worldentry[newcount].count += 1;
            newcount += 1;
        }
    }
    qsort(worldentry,newcount, sizeof(WordEntry), compare);
    for (int i = 0; i < 3; i++)
    {
        printf("%s:%d\n", worldentry[i].words, worldentry[i].count);
    }
}

int main(){
    char article[1000], p[100], q[100];
    int command = 0;
    fgets(article, sizeof(article), stdin);
    scanf("%s", p);
    scanf("%s",q);
    scanf("%d", &command);
    article[strcspn(article,"\n")] = 0;
    char *token = strtok(article, " ");
    char *arr[1000];
    int totalcount = 0;
    while (token != NULL)
    {
        arr[totalcount++] = token;
        token = strtok(NULL, " ");
    }
    if(command == 1) insertBefore(arr, p, q, totalcount);
    else if(command == 2) replace(arr, p, q, totalcount);
    else if(command == 3) delete(arr, p, q, totalcount);
    else if(command == 4) {
        int n = 0;
        scanf("%d", &n);
        lowFrequency(arr, totalcount, n);
    }else if (command == 5) frequency(arr, totalcount);
}