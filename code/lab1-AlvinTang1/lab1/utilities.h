#ifndef utilities_h
#define utilities_h
#include <stdlib.h>
#include <stdio.h>
void**	malloc2D(size_t	rows,	size_t cols,	size_t sizeOfType);
void	free2D(void***	matrix);
void*** malloc3D(size_t rows, size_t cols, size_t depths, size_t sizeOfType);
 void	free3D(void****	Dmatrix);
#endif /* utilities_h */
