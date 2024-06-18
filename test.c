#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
    char *word;
    int count;
}wordEntry;


void insertBefore(char *article[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(article[i], p) == 0) printf("%s ", q);
        printf("%s ",article[i]);
    }
    printf("\n");
}
void replace(char *article[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(article[i], p) == 0) printf("%s ",q);
        else printf("%s ",article[i]);
    }
    printf("\n");
}

void delete(char *article[], char p[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if(strcmp(article[i], p) != 0) printf("%s ",article[i]);
    }
    printf("\n");
}

void lowfrequency(char *article[], int totalcount, int n){
    wordEntry wordentry[1000] = {0};
    int newTotal = 0;
    for (int i = 0; i < totalcount; i++){
        int found = 0;
        for (int j = 0; j < newTotal; j++){
            if(strcmp(article[i], wordentry[j].word) == 0){
                wordentry[j].count ++ ;
                found = 1;
                break;
            }
        }
        if(!found){
            wordentry[newTotal].word = article[i];
            wordentry[newTotal].count = 1;
            newTotal ++;
        }
    }
    for (int i = 0; i < totalcount; i++)
    {
        for (int j = 0; j < newTotal; j++)
        {
            if(strcmp(article[i], wordentry[j].word) == 0 && wordentry[j].count >=n){
                printf("%s ", article[i]);
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
    else return strcmp(A->word, B->word);
}

void frequency(char *article[], int totalcount){
    wordEntry wordentry[1000] = {0};
    int newTotal = 0;
    for (int i = 0; i < totalcount; i++){
        int found = 0;
        for (int j = 0; j < newTotal; j++){
            if(strcmp(article[i], wordentry[j].word) == 0){
                wordentry[j].count ++ ;
                found = 1;
                break;
            }
        }
        if(!found){
            wordentry[newTotal].word = article[i];
            wordentry[newTotal].count = 1;
            newTotal ++;
        }
    }
    qsort(wordentry, newTotal ,sizeof(wordEntry), compare);
    for (int i = 0; i < 3; i++)
    {
        printf("%s %d\n", wordentry[i].word, wordentry[i].count);
    }
        
}

int main(){
    char article[1000], p[100], q[100];
    int command = 0;
    fgets(article, sizeof(article), stdin);
    scanf("%s", p);
    scanf("%s", q);
    scanf("%d", &command);
    article[strcspn(article, "\n")] = 0;
    char *token = strtok(article, " ");
    char *arr[100];
    int totalwords = 0;
    while (token !=NULL)
    {
        arr[totalwords ++] = token;
        token = strtok(NULL, " ");
    }
    if(command == 1) insertBefore(arr, p, q, totalwords);
    else if(command == 2) replace(arr, p, q, totalwords);
    else if(command == 3) delete(arr, p, totalwords);
    else if(command == 4){
        int n = 0;
        scanf("%d", &n);
        lowfrequency(arr, totalwords, n);
    }else if(command == 5) frequency(arr, totalwords);
}

