#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10
void sender();
void receiver(int frame);
int main(){
    sender();
    return 0;
}
void sender(){
    int base=0,next_frame=0;
    char ack;
    while(base<TOTAL_FRAMES){
        for(int i=0;i<WINDOW_SIZE&&next_frame<TOTAL_FRAMES;i++){
            printf("Sender: Sending frame %d\n",next_frame);
            receiver(next_frame);
            next_frame++;
        }
        for(int i=base;i<next_frame;i++){
            printf("Receiver: Enter 'y' to acknowledge frame %d or 'n' to reject:",i);
            scanf("%c",&ack);
            if(ack=='y'||ack=='Y'){
                printf("Sender: Acknowledgement received for frame %d\n",i);
                base++;
            }
            else{
                printf("Sender: Acknowledgement not received for frame %d. Resending frame %d\n",i,base);
                next_frame=base;
                break;
            }
        }
        printf("\n");
    }
}
void receiver(int frame){
    printf("Receiver: Frame %d received successfully...\n",frame);
}
