#include <stdio.h>
#include <string.h>
#define max 30

void KMP(char *txt, char *pat) {
    int lps[max], i = 0, j = 0;
    int n = strlen(txt), m = strlen(pat);

    // Compute LPS array
    int len = 0;
    lps[0] = 0;
    while(i < m) {
        if(pat[i] == pat[len]) {
            lps[i] = ++len;
            i++;
        } else {
            if(len != 0) 
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // KMP algorithm
    i = j = 0;
    while(i < n) {
        if(pat[j] == txt[i]) {
            i++; 
            j++;
        }
        if(j == m) {
            printf("Pattern found at index %d\n", i - j + 1);
            j = lps[j - 1];
        } else if(i < n && pat[j] != txt[i]) {
            if(j != 0) 
                j = lps[j - 1];
            else 
                i++;
        }
    }
}

int main() {
    char txt[max], pat[max];
    printf("Enter the text: ");
    gets(txt);
    printf("Enter the pattern: ");
    gets(pat);

    KMP(txt, pat);
    return 0;
}