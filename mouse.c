#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>

// event1 keyboard
// event2 mouse including moving | no clicking
main(){
	int fd;
	struct input_event ie;
	//if((fd = open("/dev/input/event1" , O_RDONLY )) == -1){
	if((fd = open("/dev/input/event2" , O_RDONLY )) == -1){
		perror("can not open mouse");
		exit(1);
	}
	
	char buf[100];
	while(read( fd , &ie , sizeof(struct input_event)))
	{
		printf("time %ld.%06ld\ttype %d\t code \t value %d\n",
		ie.time.tv_sec , ie.time.tv_usec , ie.code , ie.value);
	}
}
