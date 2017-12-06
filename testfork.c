#include <stdio.h>

main(){
	
	printf("my pid is %d\n" , getpid());

	fork();

	printf("my pid is %d\n" , getpid());

}
