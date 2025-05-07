
a) Contiguous/Sequential 

#include <stdio.h>
int main() {
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &b[i]);

        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &sb[i]);

        t[i] = sb[i];
        for(j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }

    printf("\nFilename\tStart block\tLength\n");
    for(i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);

    printf("Enter file number to display: ");
    scanf("%d", &x);

    if(x > 0 && x <= n) {
        printf("\nFile name is: %d", x);
        printf("\nLength is: %d", b[x - 1]);
        printf("\nBlocks occupied:");
        for(i = 0; i < b[x - 1]; i++)
            printf(" %d", c[x - 1][i]);
        printf("\n");
    } else {
        printf("Invalid file number!\n");
    }

    return 0;
}


b) Linked 
#include <stdio.h>

struct file {
    char fname[10];
    int start;
    int size;
    int block[10];
};

int main() {
    struct file f[10];
    int i, j, n;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);

        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;

        printf("Enter number of blocks: ");
        scanf("%d", &f[i].size);

        printf("Enter block numbers: ");
        for(j = 1; j < f[i].size; j++) {
            scanf("%d", &f[i].block[j]);
        }
    }

    printf("\nFile\tStart\tSize\tBlocks\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for(j = 0; j < f[i].size - 1; j++) {
            printf("%d--->", f[i].block[j]);
        }
        printf("%d\n", f[i].block[j]);
    }

    return 0;
}


c) Indexed

#include <stdio.h>

int main() {
    int n, m[20], i, j, sb[20], b[20][20], x;

    // Get number of files
    printf("Enter the number of files: ");
    scanf("%d", &n);

    // Collect file info
    for (i = 0; i < n; i++) {
        printf("\nEnter index block of File %d: ", i + 1);
        scanf("%d", &sb[i]);

        printf("Enter number of blocks for File %d: ", i + 1);
        scanf("%d", &m[i]);

        printf("Enter the block numbers for File %d:\n", i + 1);
        for (j = 0; j < m[i]; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Display file index info
    printf("\nFile\tIndex Block\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, sb[i], m[i]);
    }

    // Select a file to display its blocks
    printf("\nEnter the file number to display its blocks (1 to %d): ", n);
    scanf("%d", &x);

    if (x < 1 || x > n) {
        printf("Invalid file number entered.\n");
        return 1;
    }

    printf("\nFile Number: %d", x);
    printf("\nIndex Block: %d", sb[x - 1]);
    printf("\nBlocks occupied:");

    for (j = 0; j < m[x - 1]; j++) {
        printf(" %d", b[x - 1][j]);
    }

    printf("\n");
    return 0;
}
