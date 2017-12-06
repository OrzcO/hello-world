#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// 	ls -l ls.txt | wc
main(){

	int rv = fork();
	
	char buf[512];
	int size;
	if(0==rv){
		wait(NULL);

		int FD = open("ls.txt" , O_RDONLY);
			
		execlp("wc" , "wc" , "ls.txt" , NULL);	
	}
	else{
		char *av[] = {"ls" , "-l" , "ls.txt" ,NULL};
		
		int fd = open("haha.txt", O_WRONLY | O_CREAT);
		close(1);
		dup(fd);
		close(fd);
	
		execvp("ls" , av);

	//	char *av[] = {"cat" , "ls.txt" , NULL };
	//	execvp( "cat" , av);
	}

}
