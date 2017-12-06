#include <stdio.h>
#include <fcntl.h>
#include <utmp.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void show_time(long ltime){
	char * cp;
	cp = ctime(&ltime);
	printf("%12.12s" , cp + 4);
	
}

void show(struct utmp * u){
	if(u->ut_type != USER_PROCESS)
		return;
	printf("%-8s" , u->ut_user);
	printf("%-10s" , u->ut_line);
	show_time(u->ut_time);
	printf("(%s)" , u->ut_host);
	printf("\n");
}

main(){
	int fd;
	struct utmp _utmp;
	int len = sizeof(_utmp);

	if((fd = open(UTMP_FILE , O_RDONLY )) == -1){
		perror("file cannot open");
		exit(1);
	}
	else
	{
		while(read(fd ,&_utmp , len ) == len)
		{
			show(&_utmp);
		}
	}
	close(fd);
}
