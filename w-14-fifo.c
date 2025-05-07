#include <stdio.h>

int main() {
    int i, j = 0, k, n, fno, a[50], frame[10], avail, pagefault = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &fno);

    printf("Enter the number of reference strings: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize frame slots to -1
    for(i = 0; i < fno; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement Algorithm\n");
    printf("Reference string:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");

    for(i = 0; i < n; i++) {
        printf("Reference %d -> ", a[i]);
        avail = 0;

        for(k = 0; k < fno; k++) {
            if(frame[k] == a[i]) {
                avail = 1; // Page already in frame
                break;
            }
        }

        if(avail == 0) { // Page fault
            frame[j] = a[i];
            j = (j + 1) % fno;
            pagefault++;

            for(k = 0; k < fno; k++) {
                if(frame[k] != -1)
                    printf("%2d ", frame[k]);
            }
        } else {
            printf("No page fault");
        }

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pagefault);

    return 0;
}
