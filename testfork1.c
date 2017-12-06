#include <stdio.h>
#include <stdlib.h>

main(){

	int sn , pid = getpid();	

	printf("I an parent, my pid is %d\n" , getpid());

	printf("i need source\n");
	
	sn = fork();

	if(sn == 0){
		printf("i am buying souce\n");
		sleep(30);
		printf("i am at home\n");
		return 0;
	}
	else
	{
		wait(NULL);
		printf("let's cook\n");
	}
}
