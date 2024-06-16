#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void insertBefore(char *article, char *p, char *q) {
    int pLen = strlen(p);
    int qLen = strlen(q);
    char *pos = article;
    while ((pos = strstr(pos, p)) != NULL) {
        if ((pos == article || isspace(*(pos - 1))) && (isspace(*(pos + pLen)) || *(pos + pLen) == '\0')) {
            int offset = pos - article;
            int articleLen = strlen(article);
            memmove(pos + qLen + 1, pos, articleLen - offset + 1);
            memcpy(pos, q, qLen);
            pos[qLen] = ' ';
            pos += qLen + pLen + 1;
        } else {
            pos += pLen;
        }
    }
}

void replace(char *article, char *p, char *q){
    char *pos = article;
    int plen = strlen(p);
    int qlen = strlen(q);
    while ((pos = strstr(pos, p)) != NULL) {
        memmove(pos + qlen, pos + plen, strlen(pos + plen) + 1);
        memcpy(pos, q, qlen);
        pos += qlen;
    }
}

void deleteWord(char *article, char *p){
    char *pos = article;
    int plen = strlen(p);
    while ((pos = strstr(pos, p)) != NULL) {
        memmove(pos, pos + plen, strlen(pos + plen) + 1);
    }
}

void countFrequency(char *article, int deleteNum){
    char *words[50];
    int freq[50] = {0};
    int count = 0;
    char articleCopy[1000];
    strcpy(articleCopy, article);

    char *token = strtok(articleCopy, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[count] = token;
            freq[count] = 1;
            count++;
        }
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {
        if (freq[i] < deleteNum) {
            deleteWord(article, words[i]);
        }
    }
}

void removeExtraSpaces(char *str) {
    char *dest = str;
    char *src = str;
    while (*src != '\0') {
        while (isspace(*src) && (src == str || isspace(*(src - 1)))) {
            src++;
        }
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main() {
    char article[1000], p[22], q[22];
    int command = 0;
    fgets(article, sizeof(article), stdin);
    fgets(p, sizeof(p), stdin);
    fgets(q, sizeof(q), stdin);
    scanf("%d", &command);
    article[strcspn(article, "\n")] = '\0';
    p[strcspn(p, "\n")] = '\0';
    q[strcspn(q, "\n")] = '\0';

    if (command == 1) {
        insertBefore(article, p, q);
        removeExtraSpaces(article);
        printf("%s\n", article);
    } else if (command == 2) {
        replace(article, p, q);
        removeExtraSpaces(article);
        printf("%s\n", article);
    } else if (command == 3) {
        deleteWord(article, p);
        removeExtraSpaces(article);
        printf("%s\n", article);
    } else if (command == 4) {
        int delete_num = 0;
        scanf("%d", &delete_num);
        countFrequency(article, delete_num);
        removeExtraSpaces(article);
        printf("%s\n", article);
    } else if(command == 5){

    }

    return 0;
}
