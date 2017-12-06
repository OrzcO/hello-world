#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int order = 0;
int count = 0;
void c_print()
{
	printf("共计 : %d\n\n" , count);
	exit(0);
}

// 父进程如果只在pipe里放一句话,两个进程将会抢夺pipe里的这句话,最后只有一个人可以打印出来  write两次就好了
// 如果不sleep 发现一个进程会连续都出所有的pipe里的两句话,加了sleep就好了

main(){
	int fd[2] , pid1 ,pid2;

	pipe(fd);

	
	while(-1==(pid1=fork()));
	if(pid1 == 0)		// child1
	{
		close(fd[1]);
		char buf[1024];
		while(1)
		{
			read(fd[0] , buf , 1024);
			if(order == 0)
			{
				order = 1;
				printf("(先)pipe1 : %s\n" , buf);
				fflush(stdout);
			}
			else
			{
				order = 0;
				printf("(后)pipe1 : %s\n" , buf);
				fflush(stdout);
			}
			sleep(1);
		}

	}
	else			// parent
	{
		while(-1==(pid2 = fork()));
		if(pid2 == 0)	// child2
		{

			close(fd[1]);
			char buf[1024];
			while(1)
			{
				read(fd[0] , buf , 1024);
				if(order == 0)
				{
					order = 1;
					printf("(先)pipe2 : %s\n" , buf);
					fflush(stdout);
				}
				else
				{
					order = 0;
					printf("(后)pipe2 : %s\n" , buf);
					fflush(stdout);
				}
				sleep(1);
			}
		}
		else		// parent
		{
			signal(SIGINT , c_print);
			
			close(fd[0]);
			char buf[1024];
			while(scanf("%s" , buf) != 0)
			{
				write(fd[1] ,buf , sizeof(buf) );
				write(fd[1] ,buf , sizeof(buf) );
				count ++;
			}
		}

	}

}
