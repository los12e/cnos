9.a factorial)
#include <stdio.h>
int main() {
    int a, i;
    unsigned long long fact = 1;  // Use long long for big factorials
    printf("Enter a number: ");
    scanf("%d", &a);
    if (a < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for (i = 2; i <= a; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", a, fact);
    }
    return 0;
}
O/P:-
 Enter a number: 5
Factorial of 5 = 120


9.b):-PARENT
#include<stdlib.h>
#include<string.h>
int global=10;
void main()
{
int local=20;
pid_t pid;
printf("before fork\n");
printf("pid=%d,global=%d,local=%d\n",getpid(),global,local);
pid=fork();
if(pid<0)
printf("failed to create child");
else if(pid==0)
{
printf("after fork\n");global++;
local++;
}
else if(pid>0)
sleep(2);
printf("cid=%d,global=%d,local=%d\n",getpid(),global,local);
exit(0);
}
O/P:-
 before fork
pid=4437,global=10,local=20
after fork
cid=4438,global=11,local=21
cid=4437,global=10,local=20

9.c):-PIPE
 #include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h> /* contains prototype for wait */
int main(void){
int pid;
int status;
printf("Hello World!\n");
pid = fork( );
if(pid == -1) /* check for error in fork */
{
perror("bad fork");
exit(1);
}
if (pid == 0)
printf("I am the child process.\n");
else { wait(&status); /* parent waits for child to finish */
printf("I am the parent process.\n");
return 0;
}
}
o/p:-
Hello World!
I am the child process.
I am the parent process.
