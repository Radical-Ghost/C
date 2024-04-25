#include <stdio.h>

void print_frame(int frames[], int num_frames) {
    for (int k = 0; k < num_frames; k++)
        if (frames[k] != -1)
            printf("%d ", frames[k]);
}

void print_table(int num_pages, int num_frames, int pages[]) {
    int frames[num_frames], last_used[num_frames], miss = 0, hits = 0, i, j;

    for (i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    printf("\n|\tPage\t|\tFrames\t|\tStatus\t|\n");

    for (i = 0; i < num_pages; i++) {
        int hit = 0;
        printf("|\t%d\t|\t", pages[i]);

        for (j = 0; j < num_frames; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                hits++;
                last_used[j] = i;

                print_frame(frames, num_frames);

                printf("\t|\tH\t|\n");
                break;
            }
        }

        if (!hit) {
            int lru = 999, oldest_frame = 0;
            for (j = 0; j < num_frames; j++) {
                if (last_used[j] < lru) {
                    lru = last_used[j];
                    oldest_frame = j;
                }
            }

            frames[oldest_frame] = pages[i];
            last_used[oldest_frame] = i;
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