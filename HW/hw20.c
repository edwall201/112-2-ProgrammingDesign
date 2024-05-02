#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to replace word P with Q in the article
void replaceWord(char *article, char *p, char *q) {
    char *pos = article;
    int pLen = strlen(p);
    int qLen = strlen(q);
    while ((pos = strstr(pos, p)) != NULL) {
        memmove(pos + qLen, pos + pLen, strlen(pos + pLen) + 1);
        memcpy(pos, q, qLen);
        pos += qLen;  // Move the pointer to the end of the replaced word
    }
}

// Function to insert word Q before word P in the article
void insertBefore(char *article, char *p, char *q) {
    char *pos = strstr(article, p);
    while (pos != NULL) {
        int articleLen = strlen(article);
        int pLen = strlen(p);
        int qLen = strlen(q);
        memmove(pos + qLen + 1, pos, articleLen - (pos - article) + 1);
        memcpy(pos, q, qLen);
        pos[qLen] = ' ';  // Add a space between the inserted word and the existing word
        pos = strstr(pos + qLen + pLen + 1, p);  // Find the next occurrence of the word
    }
}

// Function to insert word Q after word P in the article
void insertAfter(char *article, char *p, char *q) {
    char *pos = article;
    int pLen = strlen(p);
    int qLen = strlen(q);
    while ((pos = strstr(pos, p)) != NULL) {
        char *insertPos = pos + pLen;  // Position to insert after the found word
        memmove(insertPos + qLen + 1, insertPos, strlen(insertPos) + 1);  // Move characters after insert position
        insertPos[0] = ' ';  // Add a space after the found word
        memcpy(insertPos + 1, q, qLen);  // Insert Q after the found word
        pos = insertPos + qLen + 1;  // Move the pointer to the end of the inserted word
    }
}


// Function to delete word P from the article
void deleteWord(char *article, char *p) {
    char *pos = article;
    int pLen = strlen(p);
    while ((pos = strstr(pos, p)) != NULL) {
        memmove(pos, pos + pLen + 1, strlen(pos + pLen) + 1);
    }
}

// Function to count word frequencies and sort them
void countFrequency(char *article) {
    char *words[50]; // Assuming maximum 50 words in the article
    int freq[50] = {0};
    int count = 0;

    // Tokenize the article into words
    char *token = strtok(article, " ");
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

    // Sort words by frequency in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (freq[j] < freq[j + 1] || (freq[j] == freq[j + 1] && strcmp(words[j], words[j + 1]) > 0)) {
                int tempFreq = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = tempFreq;

                char *tempWord = words[j];
                words[j] = words[j + 1];
                words[j + 1] = tempWord;
            }
        }
    }

    // Output sorted words and frequencies
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", words[i], freq[i]);
    }
}

int main() {
    char article[1000], p[22], q[22];
    
    // Input article, P, and Q
    fgets(article, sizeof(article), stdin);
    fgets(p, sizeof(p), stdin);
    fgets(q, sizeof(q), stdin);

    // Remove newline characters from inputs
    article[strcspn(article, "\n")] = '\0';
    p[strcspn(p, "\n")] = '\0';
    q[strcspn(q, "\n")] = '\0';

    char *original = strdup(article);
    char *original1 = strdup(article);
    char *original2 = strdup(article);
    if (strcspn(article, p) == strlen(article))
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%s\n", article);
        }
        countFrequency(original);
    }
    else
    {
        replaceWord(article, p, q);
        printf("%s\n", article);
        insertBefore(original1, p, q);
        printf("%s\n", original1);
        deleteWord(original1, p);
        // printf("%s\n", original);
        if (strstr(original, p) == NULL){}
        else deleteWord(original1, q);
        
        printf("%s\n", original1);
        countFrequency(original);
    }

    return 0;
}
