#include "main.h"
#include <unistd.h>
#include <stdlib.h>

void fork_process(pid_t child_pid, char *real_path, char **av, char *buffer, int* status)
{
	if (child_pid == 0)
	{
		execve(real_path, av, environ);
		exit(0);
	}
	else
	{
		wait(status);
		free_all(buffer, av, real_path);
	}
}
