#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void){

	int fd = open("test.txt",O_RDWR);
		
	pid_t rc = fork();
	
	if (rc < 0){
		fprintf(stderr,"fork failed");
		exit(1);
	} else if (rc == 0) {
		fprintf(stdout,"child process: fd is %d\n",fd);
	}else{
		fprintf(stdout,"parent process: fd is %d\n",fd);
	}
	return 0;
}
