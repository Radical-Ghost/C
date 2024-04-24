#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 256

int rabinKarp(char str[], char pattern[]) {
    int n = strlen(str), m = strlen(pattern), i, j;
    int p_hash = 0, s_hash = 0, pow = pow(10, m - 1);

    for (i = 0; i < m; i++) {
        s_hash = s_hash * 10 + (str[i] - 'a' + 1);
        p_hash = p_hash * 10 + (pattern[i] - 'a' + 1);
    }

    for (i = 0; i <= n - m; i++) {
        if (p_hash == s_hash)
            return 1;

        if (i < n - m)
            s_hash = (s_hash - ((str[i] - 'a' + 1) * pow)) * 10 +
                     (str[i + m] - 'a' + 1);
    }

    return 0;
}

int main() {
    char str[MAX], pattern[MAX];

    printf("Enter String: ");
    scanf("%s", str);

    printf("Enter Pattern: ");
    scanf("%s", pattern);

    if (rabinKarp(str, pattern))
        printf("'%s' is found!\n", pattern);
    else
        printf("'%s' is not found!\n", pattern);

    return 0;
}