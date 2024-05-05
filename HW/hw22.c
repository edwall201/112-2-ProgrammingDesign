#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_next_k(char *s, int start, int k, char case_to_check) {
    for (int i = start; i < start + k; i++) {
        if ((case_to_check == 'U' && !isupper(s[i])) || (case_to_check == 'L' && !islower(s[i]))) {
            return 0;
        }
    }
    return 1;
}

int find_max_length(char *s, int k) {
    int max_length = 0;
    int count = 0;
    char last_case = '\0';
    int length = strlen(s);
    int score_table[51] = {0};

    for (int i = 0; i < length; i++) {
        if ((isupper(s[i]) && last_case == 'U') || (islower(s[i]) && last_case == 'L')) {
            count++;
        } else {
            count = 1;
            
        }

        if (count == k) {
            char next_case = isupper(s[i]) ? 'L' : 'U';
            if (i + k < length && check_next_k(s, i + 1, k, next_case)) {
                count = 0;
                max_length += k;
                // printf("%c %d\n", s[i], i);
            } else {
                count = 1;
                
            }
        }

        last_case = isupper(s[i]) ? 'U' : 'L';
    }

    return max_length;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char s[51];
        int k;
        scanf("%s %d", s, &k);
        printf("%d\n", find_max_length(s, k));
    }

    return 0;
}