#include <stdlib.h>
#include <unistd.h>
#include "main.h"

char *path_finder(char *file, char **argv, char *buffer, char **av, char *real_path, path_h *head)
{
	char *path;

	if (file == buffer)
	{
		if ((comparestrings(file, "exit") == 0))
		{
			free_all(buffer, av, real_path);
			_exit(1);
		}
		path = findpath(file, head);
		if (path == NULL)
		{
			_printf("%s: 1: %s: not found\n", argv[0], av[0]);
			free_all(buffer, av, real_path);
			return (NULL);
		}
	}
	else
	{
		path = searchpath(file, buffer);
		if (path == NULL)
		{
			_printf("%s: 1: %s: no such file or directory\n", argv[0], av[0]);
			free_all(buffer, av, real_path);
			return (NULL);
		}
	}
	return (path);
}
