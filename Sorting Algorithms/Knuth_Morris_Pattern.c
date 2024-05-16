#include <stdio.h>
#include <string.h>
#define MAX 30

void computeLPS(int *pat, int M, int *lps) {
    int i = 1, j = 0;
    lps[0] = 0;

    while (i < M) {
        if (pat[i] == pat[j])
            lps[i++] = ++j;
        else if (j != 0)
            j = lps[j - 1];
        else
            lps[i++] = 0;
    }
}

void KMP(int *txt, int *pat) {
    int M = strlen(pat), N = strlen(txt), lps[M], i = 0, j = 0;

    computeLPS(pat, M, lps);

    while (i < N) {
        if (txt[i] == pat[j])
            i++, j++;

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && txt[i] != pat[j]) {
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