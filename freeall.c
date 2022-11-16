#include <stdlib.h>
#include "main.h"

void free_all(char *buffer, char **av, char *real_path)
{
	free(buffer);
	freevector(av);
	free(av);
	free(real_path);
}
