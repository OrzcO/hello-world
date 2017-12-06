#include <stdio.h>
#include <unistd.h>


main(){
	// char *av[] = .... NULL is not neccessary
	char *av[] = {"ls" , "-l", "/"};
	execvp("ls", av);
	printf("hello\n");
}
