#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

main(){
	
	int rv = fork();

	if(0==rv){
		wait(NULL);
		printf("i am your father\n");
	}
	else{
		int fd = open("ls.txt" , O_RDONLY);
		close(0);
		dup(fd);
		close(fd);
		// NULL is neccessary
		char *av[] = {"cat" , "ls.txt" , NULL};
		execvp("cat" , av );
	}

}
