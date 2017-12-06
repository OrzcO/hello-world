#include <stdio.h>
#include <unistd.h>


main(){
	char *av[] = {"ls" , "-l", "/" , NULL};
	execlp("ls","ls" , "-l" , "/" , NULL);
	printf("hello\n"); 
}
