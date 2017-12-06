#include <stdio.h>
#include <unistd.h>


main(){
	char *av[] = {"ls" , "-l", "/"};
	
	int rv = fork();

	if(0==rv){
		execvp("ls", av);
	}
	else{
		wait(NULL);
		printf("i am father\n");
	}

	printf("hello\n");
}
