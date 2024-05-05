#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_next_k(char *s, int start, int k, char case_to_check) {
    for (int i = start; i < start + k; i++) {
        if ((case_to_check == 'U' && !isupper(s[i])) || (case_to_check == 'L' && !islower(s[i]))) {
            return 0;
        }
    }
    return 1;
}

int find_max_length(char *s, int k) {
    int max_length = 0, i = 0, n = strlen(s);
    while (i <= n - k) {
        int first = i;
        int now = 0;
        int last_case = isupper(s[first]);  // Determine the initial expected case

        while (first + k <= n) {
            if (check_next_k(s, first, k, last_case ? 'U' : 'L')) {
                now += k;
                first += k;
                last_case = !last_case;
            } else {
                break;
            }
        }

        if (now > max_length) max_length = now;
        if (now == 0) i++;
        else i = first - k + 1; 
        
    }
    if(max_length == k) max_length =0;
    return max_length;
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        char s[51];
        int k;
        scanf("%s %d", s, &k);
        printf("%d\n", find_max_length(s, k));
    }
    return 0;
}