#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// 判断两个字符串是否互补
int is_complement(char* s, char* str1, char* str2) {
    // 分割 s 字符串成单词
    char* token;
    char* delimiters = " ";
    char* words[MAX_LEN];
    int word_count = 0;

    char temp_s[MAX_LEN];
    strcpy(temp_s, s); // 复制 s 到临时字符串以避免修改原始字符串

    token = strtok(temp_s, delimiters);
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, delimiters);
    }

    // 检查 str1 和 str2 中的单词是否在 s 中出现
    int index_str1 = -1;
    int index_str2 = -1;
    for (int i = 0; i < word_count; i++) {
        if (strstr(str1, words[i]) != NULL) {
            index_str1 = i;
        }
        if (strstr(str2, words[i]) != NULL) {
            index_str2 = i;
        }
    }

    if (index_str1 == -1 || index_str2 == -1) {
        return 0; // str1 或 str2 中有单词未在 s 中出现
    }

    // Check if str1 and str2 have any common words
    char temp_str1[MAX_LEN];
    char temp_str2[MAX_LEN];
    strcpy(temp_str1, str1); // Copy str1 to a temporary string to avoid modifying the original string
    strcpy(temp_str2, str2); // Copy str2 to a temporary string to avoid modifying the original string

    char* word;
    word = strtok(temp_str1, delimiters);
    while (word != NULL) {
        if (strstr(temp_str2, word) != NULL) {
            return 0; // Return 0 if a word from str1 is also in str2
        }
        word = strtok(NULL, delimiters);
    }

    // 检查 s 中的单词是否有被 str1 或 str2 完全包含
    for (int i = 0; i < word_count; i++) {
        if (strstr(str1, words[i]) == NULL && strstr(str2, words[i]) == NULL) {
            return 0; // s 中的单词没有被 str1 或 str2 完全包含
        }
    }

    return 1; // 互补
}

// 判断两个字符串是否等于
int is_equal(char* str1, char* str2) {
    return strcmp(str1, str2) == 0;
}

int count_complement_pairs(char* s, char* strings[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 尝试不同顺序的连接
            char temp1[MAX_LEN];
            char temp2[MAX_LEN];
            strcpy(temp1, strings[i]);
            strcpy(temp2, strings[j]);

            if (is_equal(temp1, temp2)) {
                continue; // 相同字符串不做处理
            }

            if (is_complement(s, temp1, temp2) || is_complement(s, temp2, temp1)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char s[MAX_LEN];
    char* strings[MAX_LEN];
    int n;

    // 输入字符串 s
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // 移除 fgets 添加的换行符

    // 输入字符串数量 n
    scanf("%d", &n);
    while (getchar() != '\n'); // 清空输入缓冲区

    // 输入字符串
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(MAX_LEN * sizeof(char));
        fgets(strings[i], MAX_LEN, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; // 移除 fgets 添加的换行符
    }

    // 计算互补字符串对数
    int count = count_complement_pairs(s, strings, n);
    printf("%d\n", count);

    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }

    return 0;
}
