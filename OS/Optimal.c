#include <stdio.h>

void print_frame(int frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++)
        if (frames[i] != -1)
            printf("%d ", frames[i]);
}

int predict(int pages[], int frames[], int num_pages, int num_frames,
            int page_index) {
    int res = -1, farthest = page_index;
    for (int i = 0; i < num_frames; i++) {
        int j;
        for (j = page_index; j < num_pages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == num_pages)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void print_table(int num_pages, int num_frames, int pages[]) {
    int frames[num_frames], miss = 0, hits = 0, i, j;

    for (i = 0; i < num_frames; i++)
        frames[i] = -1;

    printf("\n|\tPage\t|\tFrames\t|\tStatus\t|\n");

    for (i = 0; i < num_pages; i++) {
        int hit = 0;
        printf("|\t%d\t|\t", pages[i]);

        for (j = 0; j < num_frames; j++) {
            if (pages[i] == frames[j]) {
                hit = 1;
                hits++;

                print_frame(frames, num_frames);

                printf("\t|\tH\t|\n");
                break;
            }
        }

        if (!hit) {
            int replace_frame =
                predict(pages, frames, num_pages, num_frames, i + 1);

            frames[replace_frame] = pages[i];
            miss++;

            print_frame(frames, num_frames);

            printf("\t|\tM\t|\n");
        }
    }

    printf("\n\nPage Faults: %d", miss);
    printf("\nHits: %d", hits);
    printf("\nHit Ratio: %.2f%%", (float)hits / num_pages * 100);
    printf("\nMiss Ratio: %.2f%%", (float)miss / num_pages * 100);
}

int main() {
    int num_pages, num_frames, i;

    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    int pages[num_pages];
    printf("Enter pages: ");
    for (i = 0; i < num_pages; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    print_table(num_pages, num_frames, pages);

    return 0;
}