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
void*** malloc3D(size_t rows, size_t cols, size_t depth, size_t sizeOfType){
        void* block = malloc(sizeOfType * rows *cols*depth);
        void*** matrix3D = (void***)malloc2D(rows,cols,sizeof(void*));
        for (int	row	=	0;	row	<	rows;	++row)	{
        for (int col = 0;col<cols; ++col){
        matrix3D[row][col] = block
        +row*depth*cols*sizeOfType //column offset
				+depth*col*sizeOfType; //row offset
				}
        }
        return matrix3D;
        }
        void	free3D(void****	matrix3D)	{
        free((**matrix3D)[0]);
        free((**matrix3D));
        matrix3D = NULL;
        }
        
