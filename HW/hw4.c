#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

// Function to check if a string is an integer
int isInteger(const char *str) {
    int i = 0;

    // Check for optional negative sign
    if (str[i] == '-') {
        i++;
    }

    // Check if the rest of the string contains digits
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }

    // Check for leading zero
    if ((str[0] == '0' && i > 1) || (str[1] == '0' && i >=1)) {
        return 0;
    }


    return 1;
}

// Function to check if a string is a float
int isFloat(const char *str) {
    int i = 0;
    int dotCount = 0;
    int digitCountAfterDot = 0;

    // Check for optional negative sign
    if (str[i] == '-') {
        i++;
    }

    // Check if the rest of the string contains digits or a dot
    while (str[i] != '\0') {
        if (!isdigit(str[i]) && str[i] != '.') {
            return 0;
        }
        if (str[i] == '.') {
            dotCount++;
        } else if (dotCount == 1) {
            digitCountAfterDot++;
        }
        i++;
    }

    // Check for valid dot count and negative zero
    if (dotCount > 1 || (str[0] == '-' && i == 1) || (i == 1 && str[0] == '.')) {
        return 0;
    }

    // Check for negative zero
    if (strcmp(str, "-0.") == 0 || strcmp(str, "0.") == 0 || strcmp(str, "00") == 0) {
        return 0;
    }

    //Check for float with single digit after the decimal point
    if (dotCount == 1 && digitCountAfterDot >= 1) {
        return 1;
    }

    return 0;
}

// Function to check if a string is a variable
int isVariable(const char *str) {
    int i = 0;

    // Check if the first character is a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }

    for (i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }

    // Check length
    if (i < 1 || i > 10) {
        return 0;
    }

    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    char str[MAX_LENGTH];

    for (int i = 0; i < N; i++) {
        scanf("%s", str);

        // Determine the type of string
        if (isInteger(str)) {
            printf("integer\n");
        } else if (isFloat(str)) {
            printf("float\n");
        } else if (isVariable(str)) {
            printf("variable\n");
        } else {
            printf("string\n");
        }
    }

    return 0;
}
