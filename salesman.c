#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define SIG_OPEN 10
#define SIG_GO 12

int open_mark = 0;
int count =0;
int go_mark = 0;

void c_print()
{
	printf("count : %d\n" , count);
	exit(0);
}

void _go()
{
	go_mark = 1;
}

void _open()
{
	open_mark = 1;
}

main(){
	
	int fd , pfd;
	pfd = getpid();
	signal(SIG_OPEN , _open);
	signal(SIG_GO , _go);
	while((fd = fork()) == -1);
	
	if(fd == 0) // child proccess
	{
		while(1)
		{
			
			signal(SIG_OPEN , _open);	
			while(open_mark == 0){}

			printf("salesman : the door is open , and customer comes\n");
			//pause();
			printf("salesman : the door is closed , you can go\n");

			kill (pfd , SIG_GO);
			open_mark = 0;
		}
	}
	else // parent proccess
	{
		// signal(SIGINT, ) 写在main里会有两个count : 的打印
		signal(SIGINT , c_print);	
		while(1)
		{
			signal(SIG_GO , _go);
			printf("driver : open the door , a customer is coming\n");
			
			kill(fd , SIG_OPEN);
			
			while(go_mark == 0){}

			printf("driver : let's go");
			printf("\n\n");

			go_mark = 0;
			
			count ++ ;
			sleep(1);
		}
	}



}
