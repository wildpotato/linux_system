#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("PID=%d\n", pid);
	printf("PPID=%d\n", ppid);
	return 0;
}
