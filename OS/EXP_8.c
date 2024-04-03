#include <stdio.h>
#define MAX_FRAMES 5

int main() {
	int pages[MAX_FRAMES], frames[MAX_FRAMES], last_used[MAX_FRAMES] = {0};
	int num_pages, num_frames, page_faults = 0, hits = 0, i, j, k;

	printf("Enter number of pages: ");
	scanf("%d", &num_pages);

	printf("Enter pages: ");
	for (i = 0; i < num_pages; i++)
		scanf("%d", &pages[i]);

	printf("Enter number of frames: ");
	scanf("%d", &num_frames);

	for (i = 0; i < num_frames; i++)
		frames[i] = -1;

	printf("\n|\tPage\t|\tFrames\t|\tStatus\t|\n");
	for (i = 0; i < num_pages; i++) {
		int page = pages[i];
		int hit = 0;

		printf("|\t%d\t|\t", page);

		for (j = 0; j < num_frames; j++) {
			if (frames[j] == page) {
				hit = 1;
				hits++;
				for (k = 0; k < num_frames; k++)
					printf("%d ", frames[k]);
				printf("\t|\tH\t|\n");
				last_used[j] = i;
				break;
			}
		}

		if (!hit) {
			int replace_index = 0;
			int min_last_used = 9999;
			for (j = 0; j < num_frames; j++) {
				if (frames[j] == -1) {
					replace_index = j;
					break;
				}

				if (last_used[j] < min_last_used) {
					min_last_used = last_used[j];
					replace_index = j;
				}
			}

			frames[replace_index] = page;
			for (k = 0; k < num_frames; k++)
				if (frames[k] != -1)
					printf("%d ", frames[k]);
			printf("\t|\tM\t|\n");
			page_faults++;
			last_used[replace_index] = i;
		}
	}

	printf("\n\nPage Faults: %d", page_faults);
	printf("\nHits: %d", hits);
	printf("\nHit Ratio: %.2f%%", (float)hits / num_pages * 100);
	printf("\nMiss Ratio: %.2f%%", (float)page_faults / num_pages * 100);
}