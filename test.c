#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char *word;
    int count;
} wordEntry;

void insertBefore(char *article[], char p[], char q[], int totalocunt){
    char *newArticle[1000];
    int newCount = 0;
    for (int i = 0; i < totalocunt; i++)
    {
        if(strcmp(article[i], p) == 0) newArticle[newCount ++] = q;
        newArticle[newCount ++] = article[i];
    }
    for (int i = 0; i < newCount; i++)
    {
        printf("%s ", newArticle[i]);
    }
    printf("\n");
    
}

void replace(char *article[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
        if (strcmp(article[i], p) == 0) printf("%s ", q);
        else printf("%s ", article[i]);   
    }
    printf("\n");
}

void delete(char *article[], char p[], char q[], int totalcount){
    for (int i = 0; i < totalcount; i++)
    {
       if (strcmp(article[i], p) != 0) printf("%s ", article[i]);
    }
    printf("\n");
}

void lowfrequency(char *article[], int n, int totalcount){
    wordEntry wordentry[1000] = {0};
    int uniqueword = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < uniqueword; j++)
        {
            if(strcmp(article[i], wordentry[j].word) == 0){
                wordentry[j].count ++;
                found = 1;
                break;
            }
        }
        if(!found){
            wordentry[uniqueword].word = article[i];
            wordentry[uniqueword].count ++;
            uniqueword ++;
        }   
    }
    for (int i = 0; i < totalcount; i++)
    {
        for (int j = 0; j < uniqueword; j++)
        {
            if(strcmp(article[i], wordentry[j].word) == 0 && wordentry[j].count >=3){
                printf("%s ", article[i]);
            }
        }
    }
    printf("\n");
}

int compare(const void *a, const void *b){
    wordEntry *word1 = (wordEntry *)a;
    wordEntry *word2 = (wordEntry *)b;
    if(word1 -> count != word2 ->count) return word1->count-word2->count;
    else return strcmp(word1->word, word2->word);
}

void frequentCount(char *article[], int totalcount){
    wordEntry wordentry[1000] = {0};
    int uniqueword = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < uniqueword; j++)
        {
            if(strcmp(article[i], wordentry[j].word) == 0){
                wordentry[j].count ++;
                found = 1;
                break;
            }
        }
        if(!found){
            wordentry[uniqueword].word = article[i];
            wordentry[uniqueword].count ++;
            uniqueword ++;
        }   
    }
    qsort(wordentry, uniqueword, sizeof(wordEntry), compare);
    for (int i = 0; i < 3; i++)
    {
        printf("%s: %d", wordentry[i].word, wordentry[i].count);
        printf("\n");
    }
}

int main(){
    char article[1000], p[100], q[100];
    int command = 0;
    fgets(article, sizeof(article), stdin);
    article[strcspn(article,"\n")] = 0;
    scanf("%s", p);
    scanf("%s", q);
    scanf("%d", &command);
    char *arr[1000];
    int totalcount = 0;
    char *token = strtok(article, " ");
    while (token != NULL)
    {
        arr[totalcount ++] =token;
        token = strtok(NULL, " ");
    }
    if(command == 1) insertBefore(arr, p, q, totalcount);
    else if(command == 2) replace(arr, p, q, totalcount);
    else if(command == 3) delete(arr, p, q, totalcount);
    else if(command == 4){
        int n = 0;
        scanf("%d", &n);
        lowfrequency(arr, n, totalcount);
    }
    else if(command == 5) frequentCount(arr, totalcount);
     
    return 0;
}