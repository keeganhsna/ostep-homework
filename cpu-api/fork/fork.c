#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

	int x = 100;
	
	pid_t rc = fork();
	
	if (rc < 0){
		fprintf(stderr,"fork failed");
		exit(1);
	} else if (rc == 0) {
		fprintf(stdout, "child: pre-subtract: %d\n",x);
		x--;
		fprintf(stdout, "child: post-subtract: %d\n",x);
	}else{
		
		fprintf(stdout, "parent: print in else %d\n",x);
	}
	return 0;
}
