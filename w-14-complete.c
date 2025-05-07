a) FIFO 
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


b) LRU 
#include <stdio.h>

int main() {
    int i, j, k, n, fno, a[50], frame[10], lru[10], pagefault = 0, avail, max, pos;

    printf("Enter the number of frames: ");
    scanf("%d", &fno);

    printf("Enter the number of reference strings: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < fno; i++) {
        frame[i] = -1;
        lru[i] = 0;
    }

    printf("\nLRU Page Replacement Algorithm\n");
    printf("Reference string:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");

    for(i = 0; i < n; i++) {
        printf("Reference %d -> ", a[i]);
        avail = 0;

        // Check if the page is already in frame
        for(j = 0; j < fno; j++) {
            if(frame[j] == a[i]) {
                avail = 1;
                lru[j] = 0; // Reset LRU for this frame
                break;
            }
        }

        if(avail == 0) { // Page fault
            pos = -1;
            // Find an empty frame
            for(j = 0; j < fno; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find LRU
            if(pos == -1) {
                max = lru[0];
                pos = 0;
                for(j = 1; j < fno; j++) {
                    if(lru[j] > max) {
                        max = lru[j];
                        pos = j;
                    }
                }
            }

            frame[pos] = a[i];
            lru[pos] = 0;
            pagefault++;
        }

        // Update LRU counters
        for(j = 0; j < fno; j++) {
            if(frame[j] != -1 && j != pos && frame[j] != a[i]) {
                lru[j]++;
            }
        }

        // Display current frame status
        for(j = 0; j < fno; j++) {
            if(frame[j] != -1)
                printf("%2d ", frame[j]);
        }
        if(avail) printf("No page fault");
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pagefault);

    return 0;
}





c)OPTIMAL
#include<stdio.h>
int main()
{
int i,j,l,min,flag1,n,a[50],temp,frame[10],flag,fno,k,avail,pagefault=0,opt[10];
printf("\nEnter the number of Frames : ");
scanf("%d",&fno);
printf("\nEnter number of reference string :");
scanf("%d",&n);
printf("\n Enter the Reference string :\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<fno;i++)
{
frame[i]= -1;
opt[i]=0;
}
printf("\nLFU Page Replacement Algorithm\n\nThe given reference string is:\n\n");
for(i=0;i<n;i++)
printf(" %d ",a[i]);
printf("\n");
j=0;
for(i=0;i<n;i++)
{
flag=0;
flag1=0;
printf("\nReference No %d-> ",a[i]);
avail=0;
for(k=0;k<fno;k++)
if(frame[k]==a[i])
{
avail=1;
break;
}
if(avail==0)
{
temp = frame[j];
frame[j]=a[i];
for(k=0;k<fno;k++)
{
if(frame[k]==-1)
{
j = k;
flag = 1;
break;
}
}
if(flag==0)
{
for(k=0;k<fno;k++)
{
opt[k]=0;
for(l=i;l<n;l++)
{
if(frame[k]==a[l])
{
flag1 = 1;
break;
}
}
if(flag1==1)
opt[k] = l-i;
else
{
opt[k] = -1;
break;
}
}
min = 0;
for(k=0;k<fno;k++)
if(opt[k]<opt[min]&&opt[k]!=-1)
min = k;
else if(opt[k]==-1)
{
min = k;
frame[j] = temp;
frame[k] = a[i];
break;
}
j = min;
}
pagefault++;
for(k=0;k<fno;k++)
if(frame[k]!=-1)
printf(" %2d",frame[k]);
}
printf("\n");
}
printf("\nPage Fault Is %d",pagefault);
return 0;
}
