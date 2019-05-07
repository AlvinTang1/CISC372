#ifndef utilities_h
#define utilities_h
#include <stdlib.h>
#include <stdio.h>
void**	malloc2D(size_t	rows,	size_t cols,	size_t sizeOfType);
void	free2D(void***	matrix);
#endif /* utilities_h */
