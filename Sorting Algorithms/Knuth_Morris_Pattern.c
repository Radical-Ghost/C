#include <stdio.h>
#include <string.h>
#define MAX 30

void computeLPSArray(char *pat, int M, int *lps) {
    int i = 1, len = 0;
    lps[0] = 0;

    while (i < M) {
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len != 0)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
}

void KMP(char *txt, char *pat) {
    int M = strlen(pat), N = strlen(txt), lps[M], i = 0, j = 0;

    computeLPSArray(pat, M, lps);

    while (i < N) {
        if (pat[j] == txt[i])
            i++, j++;

        if (j == M) {
            printf("Pattern found at index %d\n", i - M + 1);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char txt[MAX], pat[MAX];
    printf("Enter the text: ");
    scanf("%s", txt);

    printf("Enter the pattern: ");
    scanf("%s", pat);

    KMP(txt, pat);
    return 0;
}