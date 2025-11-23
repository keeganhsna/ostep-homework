#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char* argv[]){




	pid_t rc = fork();
	if (rc < 0){
		fprintf(stderr,"fork failed");
		exit(1);

	} else if (rc == 0) {
		execvp("/bin/ls",&argv[1]);
	}else{
	//parent process
	}

	return 0;

}
