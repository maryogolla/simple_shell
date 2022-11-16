#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
/**
 * struct path_s - defines a new structure
 * @name: first member
 * @next: second member
 */
typedef struct path_s
{
	char name[PATH_MAX];
	struct path_s *next;
} path_h;
char *tokenizepath(char *, char, int *, char **);
char *shiftcharacter(char **, int);
void copystring2(char *, char *);
void trim_end(char **);
void add_node_end(path_h **, char *);
int findpath_to_executable(path_h **);
void copystring(char *, char **);
void freevector(char **);
char *getlaststring(char **);
char *get_path_string(char **, char **);
void createlinkedlist(char*, path_h **);
char *findpath(char *, path_h *head);
char *searchpath(char *, char *);
int comparestrings(char *, char *);
void string_concat(char **, char *);
void free_list(path_h *);
int printstring(const char *);
void writeint(unsigned int, int);
int printint(int);
int calculate_numbers(unsigned int);
int printunsigned(unsigned int);
void writeunsigned(unsigned int, int);
int _putchar(char);
int _printf(const char *format, ...);
int formatchecker(va_list, const char *);
void handle_sigint(int);
void free_all(char *, char **, char *);
char *path_finder(char *, char **, char *, char **, char *, path_h *);
void fork_process(pid_t, char *, char **, char *, int *);
#endif
