#include "utilities.h"
void**	malloc2D(size_t	rows,	size_t cols,	size_t sizeOfType)	{
				void*	block	=	malloc(sizeOfType	*	rows	*	cols);
				void**	matrix	=	malloc(sizeof(void*)	*	rows);
				for (int	row	=	0;	row	<	rows;	++row)	{
								matrix[row]	=	block	+	cols	*	row	*	sizeOfType;
				}
				return matrix;
}
void	free2D(void***	matrix)	{
				free((*matrix)[0]);
				free((*matrix));
				matrix	=	NULL;
}
