#include <stdio.h>
#define max 30

int pattern_match(char *txt, char *pat) {
    int i, j;
    for (i = 0; txt[i] != '\0'; i++) {
        for (j = 0; pat[j] != '\0'; j++)
            if (txt[i + j] != pat[j])
                break;
        if (pat[j] == '\0')
            return i;
    }
    return -1;
}

int main() {
    char txt[max], pat[max];
    printf("Enter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern: ");
    scanf("%s", pat);

    int pos = pattern_match(&txt, &pat);
    if (pos != -1)
        printf("Pattern found at position %d\n", pos + 1);
    else
        printf("Pattern not found\n");
}