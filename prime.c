#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUMBER_WAIT_INTERVAL 10

int main(void){

void sigint_handler(int sig);

if(signal(SIGINT, sigint_handler) == SIG_ERR){
perror("signal");
}

int pipefds[2], buffer;

if(pipe(pipefds) == -1){
perror("pipe");
exit(EXIT_FAILURE);
}

int user, flag=0;

printf("Please enter a number to check either prime or not:\n");
scanf("%d",&user);

printf("Writing number to pipe...\n");
write(pipefds[1], &user, sizeof(user));
printf("Done.\n\n");

printf("Reading number from pipe...\n");
read(pipefds[0], &buffer, sizeof(buffer));
printf("Done.\n\n");

if((buffer>0)&&((buffer==1)||(buffer%2==0))){
printf("%d is not a prime number.\n",buffer);
flag=1;
}

else if((buffer>0)&&(buffer%2!=0)){
printf("%d is prime number.\n",buffer);
flag=0;
}

else{
printf("You have entered wrong value.\n");
}

sleep(NUMBER_WAIT_INTERVAL);

return 0;
}

void sigint_handler(int sig){
printf("\n");
EXIT_SUCCESS;
}

