13a).PAGING
#include <stdio.h>

#define MAX_FRAMES 20
#define MAX_PAGES 20

int main() {
    int framearr[MAX_FRAMES];
    int prosize, memsize, pagesize;
    int pages, frames;
    int i, frame_no, offset;
    int logical_address, physical_address;
    int base = 0; // Assuming base is 0 for simplicity

    // Input sizes
    printf("Enter the Process size (in bytes): ");
    scanf("%d", &prosize);

    printf("Enter the Main Memory size (in bytes): ");
    scanf("%d", &memsize);

    printf("Enter the Page size (in bytes): ");
    scanf("%d", &pagesize);

    // Calculate number of pages and frames
    pages = prosize / pagesize;
    frames = memsize / pagesize;

    printf("\nThe process is divided into %d pages.", pages);
    printf("\nThe main memory is divided into %d frames.\n", frames);

    // Initialize frame array
    for (i = 0; i < frames; i++)
        framearr[i] = -1;

    // Page table creation
    for (i = 0; i < pages; i++) {
        while (1) {
            printf("Enter the frame number to which page %d is allocated: ", i);
            scanf("%d", &frame_no);

            if (frame_no < 0 || frame_no >= frames) {
                printf("\tInvalid frame number. Please enter between 0 and %d.\n", frames - 1);
            } else if (framearr[frame_no] != -1) {
                printf("\tFrame %d is already occupied by page %d.\n", frame_no, framearr[frame_no]);
            } else {
                framearr[frame_no] = i;
                break;
            }
        }

        // Translate a logical address to physical address for this page
        printf("Enter offset (displacement) within the page: ");
        scanf("%d", &offset);

        if (offset < 0 || offset >= pagesize) {
            printf("Invalid offset. It must be less than page size (%d).\n", pagesize);
            i--; // Retry this page
            continue;
        }

        physical_address = base + (frame_no * pagesize) + offset;
        printf("Physical Address for page %d, offset %d: %d\n\n", i, offset, physical_address);
    }

    // Final page table output
    printf("\nPage Table (Page -> Frame):\n");
    printf("---------------------------\n");
    for (i = 0; i < frames; i++) {
        if (framearr[i] != -1)
            printf("Page %d -> Frame %d\n", framearr[i], i);
    }

    return 0;
}
Sample Output:- 
Enter the Process size (in bytes): 1600
Enter the Main Memory size (in bytes): 3200
Enter the Page size (in bytes): 400

The process is divided into 4 pages.
The main memory is divided into 8 frames.

Enter the frame number for page 0: 3
Enter the frame number for page 1: 5
Enter the frame number for page 2: 1
Enter the frame number for page 3: 6

Enter a logical address (0 - 1599): 1180

Logical Address: 1180
Page Number: 2
Offset: 380
Mapped to Frame: 1
Physical Address: 1780



    
13b). SEGMENTATION:
#include <stdio.h>

#define MAX_SEGMENTS 10
#define MAX_SEGMENT_SIZE 20

int main() {
    int base[MAX_SEGMENTS], limit[MAX_SEGMENTS];
    int val[MAX_SEGMENTS][MAX_SEGMENT_SIZE];
    int size, i, j, logical_address, segment_no, physical_address;

    // Input segment table
    printf("Enter the number of segments: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("\nEnter information for Segment %d\n", i);
        printf("Base Address: ");
        scanf("%d", &base[i]);

        printf("Limit: ");
        scanf("%d", &limit[i]);

        // Input values stored in each segment
        for (j = 0; j < limit[i]; j++) {
            printf("Enter value at address %d: ", base[i] + j);
            scanf("%d", &val[i][j]);
        }
    }

    // Display segment table
    printf("\n\n**** SEGMENT TABLE ****\n");
    printf("Segment No.\tBase\tLimit\n");
    for (i = 0; i < size; i++) {
        printf("%d\t\t%d\t%d\n", i, base[i], limit[i]);
    }

    // Segment access
    printf("\nEnter Segment Number: ");
    scanf("%d", &segment_no);

    if (segment_no < 0 || segment_no >= size) {
        printf("Invalid Segment Number!\n");
        return 1;
    }

    printf("Enter Logical Address (Offset): ");
    scanf("%d", &logical_address);

    if (logical_address < 0 || logical_address >= limit[segment_no]) {
        printf("Invalid Logical Address! It exceeds segment limit.\n");
        return 1;
    }

    physical_address = base[segment_no] + logical_address;
    printf("\nMapped Physical Address = %d", physical_address);
    printf("\nValue at that address = %d\n", val[segment_no][logical_address]);

    return 0;
}
