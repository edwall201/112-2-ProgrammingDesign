#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char *word;
    int count;
} WordEntry;

void insertBefore(char *article[], char p[], char q[], int totalwork) {
    char *newArticle[1000];
    int newWords = 0;
    for (int i = 0; i < totalwork; i++) {
        if (strcmp(article[i], p) == 0) newArticle[newWords++] = q;
        newArticle[newWords++] = article[i];
    }
    for (int i = 0; i < newWords; i++) {
        printf("%s ", newArticle[i]);
    }
    printf("\n");
}

void replace(char *article[], char p[], char q[], int totalcount) {
    for (int i = 0; i < totalcount; i++) {
        if (strcmp(article[i], p) == 0) printf("%s ", q);
        else printf("%s ", article[i]);
    }
    printf("\n");
}

void delete(char *article[], char p[], int totalcount) {
    for (int i = 0; i < totalcount; i++) {
        if (strcmp(article[i], p) != 0) printf("%s ", article[i]);
    }
    printf("\n");
}

void removelowfreq(char *article[], int n, int totalcount){
    WordEntry entries[1000] = {0};
    int uniquesWord = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < uniquesWord; j++){
            if(strcmp(article[i], entries[j].word) == 0){
                entries[j].count ++;
                found = 1;
                break;
            }
        }
        if(!found){
            entries[uniquesWord].word = article[i];
            entries[uniquesWord].count = 1;
            uniquesWord ++;
        }
    }
    for (int i = 0; i < totalcount; i++)
    {
        for (int j = 0; j < uniquesWord; j++)
        {
            if (strcmp(article[i], entries[j].word) == 0 && entries[j].count >=n)
            {
                printf("%s ", article[i]);
                break;
            }
        }
    }
    printf("\n");
}

int compare(const void *a, const void *b){
    WordEntry *word1 = (WordEntry *)a;
    WordEntry *word2 = (WordEntry *)b;
    if(word1 -> count != word2 -> count) return word1->count-word2->count;
    else return strcmp(word1->word, word2->word);
}

void outputFreq(char *article[], int totalcount){
    WordEntry entries[1000] = {0};
    int uniquesWord = 0;
    for (int i = 0; i < totalcount; i++)
    {
        int found = 0;
        for (int j = 0; j < uniquesWord; j++){
            if(strcmp(article[i], entries[j].word) == 0){
                entries[j].count ++;
                found = 1;
                break;
            }
        }
        if(!found){
            entries[uniquesWord].word = article[i];
            entries[uniquesWord].count = 1;
            uniquesWord ++;
        }
    }
    qsort(entries, uniquesWord, sizeof(WordEntry), compare);
    for (int i = 0; i < 3; i++)
    {
        printf("%s: %d", entries[i].word, entries[i].count);
        printf("\n");
    }
    
}


int main() {
    char article[1000], p[100], q[100];
    int command = 0, n;
    fgets(article, sizeof(article), stdin);
    article[strcspn(article, "\n")] = 0;
    scanf("%s", p);
    scanf("%s", q);
    scanf("%d", &command);
    if (command == 4) scanf("%d", &n);

    char *arr[1000];
    int totalWorks = 0;
    char *token = strtok(article, " ");
    while (token != NULL) {
        arr[totalWorks++] = token;
        token = strtok(NULL, " ");
    }

    if (command == 1) {
        insertBefore(arr, p, q, totalWorks);
    } else if (command == 2) {
        replace(arr, p, q, totalWorks);
    } else if (command == 3) {
        delete(arr, p, totalWorks);
    } else if (command == 4) {
        removelowfreq(arr, n, totalWorks);
    } else if(command == 5){
        outputFreq(arr, totalWorks);
    }

    return 0;
}
