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
    int max_length = 0, i = 0, n = strlen(s);
    while (i <= n - k) {
        int start = i;
        int current = 0;
        int last_case = isupper(s[start]);  // Determine the initial expected case

        while (start + k <= n) {
            if (check_next_k(s, start, k, last_case ? 'U' : 'L')) {
                current += k;
                start += k;
                last_case = !last_case;  // Toggle the case expectation
            } else {
                break;  // Segment did not match, break to try a new starting point
            }
        }

        if (current > max_length) max_length = current;
        if (current == 0) i++;  // No valid segment found at the current start, move by 1
        else i = start - k + 1;  // Start again from the last valid k segment's next position
        
    }
    if(max_length == k) max_length =0;
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