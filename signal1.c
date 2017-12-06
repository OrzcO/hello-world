#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int flag1 = 0 , flag2 = 0;
static void handler1(int sig){
	flag1 = 1;
}
static void handler2(int sig){
	flag2 = 1;
}
static void handler(int sig){
}

main(){
	int p1 ,p2;
	while((p1=fork())==-1) ;

	if(p1 == 0){
		
		while((p2=fork())==-1) ;

		if(p2 == 0){

			signal(SIGINT , handler2);
			
			while(1)
			{
				if(flag2){
					printf("child proccess1 is killed by parent\n");
					exit(1);
				}
			}
		}

		signal(SIGINT , handler1);

		while(1)
		{
			if(flag1){
				printf("child proccess2 is killed by parent\n");
				fflush(stdout);
				exit(0);
			}
		}

	}
	else
	{
		signal(SIGINT , handler);		
	
		wait(NULL);
		
		
		printf("parent proccess is killed!\n");
		
	}
}
