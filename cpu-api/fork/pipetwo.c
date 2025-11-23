#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){



	int p[2];
	pipe(p);
	pid_t p1 = fork();
	pid_t p2 = fork();


	if (p1 < 0 || p2 < 0){
		printf("fork failed");
		exit(1);
	}

	if (p1 ==0){
		close(p[0]);
		dup2(p[1], STDOUT_FILENO);
		close(p[1]);
		execlp("ls","ls","-l",NULL);
		

	}
	
	if (p2 ==0){
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		close(p[0]);

		execlp("wc","wc","-l",NULL);
		exit(1);

	}

	close(p[0]);
	close(p[1]);

	wait(NULL);
	wait(NULL);
	return 0;

}
