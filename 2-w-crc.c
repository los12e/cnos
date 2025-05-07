#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FRAME_SIZE 50
#define GEN_SIZE 50

void computeCRC();
void copyFrame();

int i,j,k,gen_size=0;
int gen[GEN_SIZE],frame[FRAME_SIZE], rem[FRAME_SIZE], temp[FRAME_SIZE];

void computeCRC(){
    for(i=0;i<=j-gen_size;i++){
        if(rem[i]==1){
            for(k=0;k<gen_size;k++){
                rem[i+k]^=gen[k];
            }
        }
    }
}

void copyFrame(){
    for(i=0;i<j;i++){
        rem[i]=temp[i];
        printf("%d",temp[i]);
    }
    printf("\n");
}
int main() {
    char poly[50], gen_str[GEN_SIZE];
    printf("\t\t***CYCLIC REDUNDANCY CHECK - 12***\n\n");
    
    memset(frame,0,sizeof(frame));
	memset(rem,0,sizeof(rem));
	memset(temp,0,sizeof(temp));
	memset(gen,0,sizeof(gen));
	printf("Enter the Polynomial in binary: ");
	fgets(poly,sizeof(poly),stdin);
	int poly_len=strlen(poly)-1;
	for(i=0;i<poly_len;i++){
	    if(poly[i]=='0'||poly[i]=='1'){
	        frame[i]=poly[i]-'0';
	    }
	    else{
	        printf("Invalid Polynomial! Exiting..\n");
	        return 1;
	    }
	}
	
	printf("Enter the generator polynomial (e.g., 1101): ");
	fgets(gen_str,sizeof(gen_str),stdin);
	gen_size=strlen(gen_str)-1;
	
	for(i=0;i<gen_size;i++){
	    if(gen_str[i]=='0'||gen_str[i]=='1'){
	        gen[i]=gen_str[i]-'0';
	        }
	   else{
	        printf("Inavlid Generator! Exiting ..\n");
	        return 1;
	        }
	    }
	    
    j=poly_len+gen_size-1;
    for(i=0;i<poly_len;i++){
        temp[i]=frame[i];
    }
    
	for(i=poly_len;i<j;i++){
	    temp[i]=0;
	}
	
	printf("\nFrame After Appending 0's: ");
	copyFrame();
	computeCRC();
	
	printf("\n The Remainder is: ");
	for(i=poly_len;i<j;i++){
	    temp[i]=rem[i];
	    printf("%d",rem[i]);
	}
	printf("\n");
	
	printf("\n Transmitting FRAME..\n\n Transmitted FRAME is: ");
	copyFrame();
	
	printf("\n Checking for errors..\n\nRecieved Frame: ");
	copyFrame();
	computeCRC();
	printf("\n The Remainder is: ");
	int error=0;
	for(i=poly_len;i<j;i++){
	    printf("%d",rem[i]);
	    if(rem[i]!=0){
	        error=1;
	    }
	}
	printf("\n");
	if(!error){
	    printf("\nSUCCESS");
	}
	else{
	    printf("\nFAILURE");
	}

}
