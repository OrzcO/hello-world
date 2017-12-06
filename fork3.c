#include <stdio.h>
#include <unistd.h>

main(){
	int p1 , p2 , p3;

	while(-1==(p1=fork()));
	if(p1 == 0){
		while(-1==(p2=fork()));
		if(p2 == 0){
			while(-1==(p3=fork()));
			if(p3 == 0){
				wait(NULL);
				printf("d\t pid=%d\n" , getpid());
			}
			else
			{	
				printf("c\t pid=%d\n" , getpid());
			}
		}
		else
		{
			printf("b\t pid=%d\n" , getpid());
		}
	}
	else
	{
		printf("a\t pid=%d\n" , getpid());
	}
	
}
