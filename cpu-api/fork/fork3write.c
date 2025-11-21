#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void){



	int p[2];
	if(pipe(p) ==-1){
		perror("pipe");
	}

	pid_t rc = fork();
	if (rc < 0){
		fprintf(stderr,"fork failed");
		exit(1);

	} else if (rc == 0) {
		close(p[0]);
		char *msg = "Hello!";
		printf("im here\n");
		fprintf(stdout,"%s\n",msg);
		write(p[1],"x",1);
	}else{
		close(p[1]);
		char *msg = "Goodbye!";
		char c;
		printf("I'm also here den");
		fflush(stdout);
		read(p[0],&c,1);
		fprintf(stdout,"%s\n",msg);
	}
	return 0;

}
