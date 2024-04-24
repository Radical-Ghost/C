#include <stdio.h>
#include <string.h>
#define MAX 30

void computeLPSArray(char *pat, int M, int *lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *txt, char *pat) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[MAX];
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Pattern found at index %d\n", i - j + 1);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    char txt[MAX], pat[MAX];
    printf("Enter the text: ");
    fgets(txt, MAX, stdin);
    txt[strcspn(txt, "\n")] = 0;
    printf("Enter the pattern: ");
    fgets(pat, MAX, stdin);
    pat[strcspn(pat, "\n")] = 0;
    KMP(txt, pat);
    return 0;
}