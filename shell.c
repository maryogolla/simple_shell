#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

extern char **environ;

int main(void)
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
	pathptr = get_path_string(&path_buffer);
	createlinkedlist(pathptr, &head);

	while (1)
	{
	printf("$ ");
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Failed to allocate space");
		return (0);
	}
	characters = getline(&buffer, &bufsize, stdin);
	if (characters == -1)
	{
		free(buffer);
		return (1);
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
		if (file == buffer)
		{
			if ((comparestrings(file, "exit") == 0))
			{
				free(buffer);
				freevector(av);
				free(av);
				free(real_path);
				_exit(status);
			}
			path = findpath(file, head);
			if (path == NULL)
			{
				printf("./hsh: %s: not found\n", av[0]);
				free(buffer);
				free(real_path);
				freevector(av);
				free(av);
				continue;
			}
		}
		else
			path = searchpath(file, buffer);
		if (path == NULL)
		{
			printf("./hsh: %s: no such file or directory\n", av[0]);
			free(real_path);
			free(buffer);
			continue;
		}
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
		av[i] = NULL;
		file = av[0];
		path = findpath(file, head);
		if (path == NULL)
		{
			printf("./hsh: %s: not found\n", av[0]);
			free(real_path);
			free(buffer);
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
		free(real_path);
		free(buffer);
		freevector(av);
		free(av);
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
	if (ptr1 == NULL)
		return;
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
char *get_path_string(char **buf)
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
