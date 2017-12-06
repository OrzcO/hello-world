#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// hello.c world.c
int main(int ac , char * av[]){
	int fd;
	char buf[256];
	if(ac != 3){
		printf("para is not enough\n");
		exit(1);
	}

	if((fd = open( av[1],O_RDONLY))== -1){
		perror("open file wrong");
		exit(1);
	}
	else{
		int fd_w;
		if((fd_w = open(av[2] , O_WRONLY|O_CREAT , 0644)) == -1){
			perror("open file wrong");
			exit(1);
		}
		else{
			int num;
			while((num = read(fd , buf , 256)) > 0)
			{
				write(fd_w , buf , num);	
			}	
		}
		close(fd_w);
		
	}
	close(fd);

	return 0;
}
