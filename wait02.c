#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t bash_pid = 14121;
	pid_t pid;
	int status;

	printf("Begin waiting for bash_pid=%d\n", bash_pid);
	pid = waitpid(bash_pid, &status, WNOHANG);
	if (pid == -1)
		perror("waitpid");
	else {
		printf("pid=%d\n", pid);
		if (WIFEXITED(status))
			printf("normal termination with exit status=%d\n",
				WEXITSTATUS(status));
		if (WIFSIGNALED(status))
			printf("Killed by signal=%d%s\n",
				WTERMSIG(status),
				WCOREDUMP(status) ? " (dumped core)" : "");
	}
	return 0;
}	
