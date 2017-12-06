#include <stdio.h>
#include <stdlib.h>

main(){

	int sn , pid = getpid();	

	printf("I an parent, my pid is %d\n" , getpid());

	printf("i need source\n");
	
	sn = fork();

	if(sn == 0){
		printf("i am buying souce\n");
		//sleep(30);
		sleep(5);
		printf("i am at home\n");
		exit(0);
	}
	else
	{
		int rv = wait(NULL);

		printf("exit = %d \t sig = %d\n" ,( rv >> 8) , (rv & 0x7F));
		printf("let's cook\n");
	}
}
