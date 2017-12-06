#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
main(){
	int fd;
	char buf [100];
	if((fd = open("/dev/pts/2" , O_WRONLY)) == -1){
		perror("open device error");
		exit(1);
	}
	
	while(fgets(buf , 100 , stdin) != NULL)
	{
		if(write(fd , buf , strlen(buf)) == -1)
			break;
	}
	close(fd);
	return 0 ;
}
