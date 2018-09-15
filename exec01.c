#include <unistd.h>
#include <stdio.h>

int main() {
	int ret;
	execl("/Users/johnnychan/Desktop/im80/linux_system/fork01.o", "fork01.o", NULL);
	if (ret == -1)
		perror("execl");
	printf("End of exec!\n");
	return 0;
}	
