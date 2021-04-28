#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
int main(){

int user, flag=0;
printf("Please enter a number to check either prime or not:\n");
scanf("%d",&user);

if((user>0)&&((user==1)||(user%2==0))){
printf("%d is not a prime number.\n",user);
flag=1;
}

else if((user>0)&&(user%2!=0)){
printf("%d is prime number.\n",user);
flag=0;
}

else{
printf("You have entered wrong value.\n");
}

return 0;
}
