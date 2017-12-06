#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int wait_mark;
void waiting() , stop();
void main()
{
	int p1 , p2;
	signal(SIGINT , stop);
	while((p1=fork())==-1);
	if(p1 > 0)
	{
	//signal(SIGINT , stop);
		while((p2=fork())==-1);
		if(p2 > 0)
		{
	//signal(SIGINT , stop);
			wait_mark = 1;
			waiting();
			kill(p1 , 10);
			kill(p2 , 12);
			wait(0);
			wait(0);
			printf("parent proccess is killed!\n");
			exit(0);
		}
		else
		{
			wait_mark = 1;
			signal(12 , stop);
			waiting();
			//lockf(1,1,0);
			printf("child proccess 2 is killed by parent!\n");
			//lockf(1,0,0);
			exit(0);
		}
	}
	else
	{
		wait_mark = 1;
		signal(10,stop);
		waiting();
		//lockf(1,1,0);
		printf("child proccess 1 is killed by parent!\n");
		//lockf(1,0,0);
		exit(0);
	
	}
}

void waiting()
{
	while(wait_mark!=0);
}

void stop()
{
	wait_mark = 0;
}



/*
 *
 * 
(1)
运行结果： 
child proccess 2 is killed by parent!
child proccess 1 is killed by parent!
parent proccess is killed!

(2)
proccess 1没有被killed，因为proccess 1 的进程里没有

	signal(SIGINT , stop);
所以proccess 1接受Ctrl c时直接结束，不会往下执行，死在了waiting()里，父进程的wait(NULL)接受proccess 1死亡的消息。

(3)
需要接受两个子进程都退出
(4)

wait(0)用来接受子进程exit(0)，当父进程接受到子进程结束后，才能继续执行

 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
