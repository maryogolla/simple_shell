#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "main.h"

void handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		_printf("\n");
		exit (0);
	}
}
int main(__attribute__((unused))int ac, char **argv, char **environ)
{
	char *buffer, *token, *token2, *currentposition, *file, *path, *pathptr;
	size_t bufsize = 100;
	ssize_t characters;
	int i = 0, flag = 0, status;
	char **av;
	char *path_buffer = malloc(sizeof(char) * 150);
	pid_t child_pid;
	char *real_path;

	path_h *head = NULL;
	pathptr = get_path_string(&path_buffer, environ);
	createlinkedlist(pathptr, &head);

	signal(SIGINT, handle_sigint);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf("#cisfun$ ");
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Failed to allocate space");
		return (1);
	}
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == -1)
	{
		free(buffer);
		_exit(1);
	}


	real_path = malloc(sizeof(char) * 30);
	trim_end(&buffer);
	currentposition = buffer;
	token = tokenizepath(buffer, ' ', &flag, &currentposition);
	if (token == NULL)
	{
		free(token);
		file = getlaststring(&buffer);
		av = malloc(sizeof(char *) * 2);
		copystring(file, &av[0]);;
		av[1] = NULL;
		path = path_finder(file, argv, buffer, av, real_path, head);
		if (path == NULL)
			continue;
		copystring2(path, real_path);
		string_concat(&real_path, file);
	}
	else
	{
		while (token != NULL)
		{
			flag++;
			i++;
			free(token);
			token = tokenizepath(buffer, ' ', &flag, &currentposition);
		}
		free(token);
		av = malloc((i + 1) * sizeof(char *));
		if (av == NULL)
			return (0);
		i = 0;
		flag = 0;
		currentposition = buffer;
		token2 = tokenizepath(buffer, ' ', &flag, &currentposition);
		while (token2 != NULL)
		{
			flag++;
			copystring(token2, &av[i]);
			free(token2);
			i++;
			token2 = tokenizepath(buffer, ' ', &flag, &currentposition);
		}
		free(token2);
		av[i] = NULL;
		file = av[0];
		path = findpath(file, head);
		if (path == NULL)
		{
			_printf("%s: 1: %s: not found\n", argv[0], av[0]);
			free_all(buffer, av, real_path);
			continue;
		}
		copystring2(path, real_path);
		string_concat(&real_path, file);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(real_path, av, environ);
		exit(0);
	}
	else
	{
		wait(&status);
		free_all(buffer, av, real_path);
	}
	}
	free(buffer);
	free(path_buffer);
	free_list(head);
	return (0);
}

void copystring(char *ptr1, char **ptr2)
{
	int i = 0;
	int j = 0;
	char *s = ptr1;
	char *p = ptr1;
	while (*p != '\0')
	{
		j++;
		p++;
	}
	*ptr2 = malloc(sizeof(char) * (j + 1));
	if (*ptr2 == NULL)
		return;
	while (*s != '\0')
	{
		(*ptr2)[i] = *s;
		s++;
		i++;
	}
	(*ptr2)[i] = '\0';
}
void freevector(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
}
char *get_path_string(char **buf, char **environ)
{
	int i = 0, l = 0;
	char *ptr;

	while (environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A')
		{
			while (environ[i][l] != '\0')
			{
				(*buf)[l] = environ[i][l];
				l++;
			}
			(*buf)[l] = '\0';
			ptr = shiftcharacter(buf, 5);
			break;
		}
		i++;
	}
	return (ptr);
}
