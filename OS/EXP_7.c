#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 5

typedef struct {
    int value;
    int inFrame;
} Page;

int main() {
    Page frames[MAX_FRAMES];
    int num_pages, num_frames, page_faults = 0, hits = 0, i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    Page *pages = malloc(num_pages * sizeof(Page));

    printf("Enter pages: ");
    for (i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i].value);
        pages[i].inFrame = 0;
    }

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    for (i = 0; i < num_frames; i++) {
        frames[i].value = -1;
        frames[i].inFrame = 0;
    }

    int oldest_frame = 0;

    printf("\n|\tPage\t|\tFrames\t|\tStatus\t|\n");
    for (i = 0; i < num_pages; i++) {
        int page = pages[i].value;
        int hit = 0;

        printf("|\t%d\t|\t", page);

        for (j = 0; j < num_frames; j++) {
            if (frames[j].value == page) {
                hit = 1;
                hits++;
                for (k = 0; k < num_frames; k++) {
                    printf("%d ", frames[k].value);
                }
                printf("\t|\tH\t|\n");
                break;
            }
        }

        if (!hit) {
            frames[oldest_frame].value = page;
            frames[oldest_frame].inFrame = 1;
            oldest_frame = (oldest_frame + 1) % num_frames;
            page_faults++;

            for (k = 0; k < num_frames; k++) {
                printf("%d ", frames[k].value);
            }
            printf("\t|\tM\t|\n");
        }
    }

    printf("\n\nPage Faults: %d", page_faults);
    printf("\nHits: %d", hits);
    printf("\nHit Ratio: %.2f%%", (float)hits / num_pages * 100);
    printf("\nMiss Ratio: %.2f%%", (float)page_faults / num_pages * 100);

    free(pages);

    return 0;
}
