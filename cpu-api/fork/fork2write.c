#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void){

	int fd = open("test.txt",O_RDWR);
	
	if (fd < 0) {
		perror("open");
		exit(1);
	}


	pid_t rc = fork();
	char *msg = "oh long johnson\n";

	if (rc < 0){
		fprintf(stderr,"fork failed");
		exit(1);

	} else if (rc == 0) {
		ssize_t n = write(fd,msg,16);
		if (n<0){
			perror("write");
			exit(1);
		}
	}else{
		ssize_t n = write(fd,msg,16);
		if (n<0){
			perror("write");
			exit(1);
		}
	
	}
	close(fd);
	return 0;

}
