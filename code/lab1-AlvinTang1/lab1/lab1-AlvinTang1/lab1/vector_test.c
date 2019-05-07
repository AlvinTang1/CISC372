#include "types.h"
#include "utilities.h"
int	smallest(const	Vector3t*	pts,int	n)
int main(int argc,char** argv)
{
	unsigned int N;
	int min,value;

	printf("“Number of elements ===>");
	fscanf(stdin, "%d", &N);
	Vector3t* points[N];
	int** matrix = malloc2D(N,3,sizeof(int));
	for(i=0,i<N,i++)
	{

	fscanf(stdin,"%d,%d,%d", matrix[i][0],matrix[i][1],matrix[i][2])
	value = sqrt(square(matrix[i][0])+square(matrix[i][1])+square(matrix[i][2]));
	if(value<min){
		min = value;
	}
}
return 0;
}
int	smallest(const Vector3t* pts, int n)
{
	int min = FLT_MAX;
	for(i=0,i<n,i++)
	{
		value = sqrt(square(Vector3t[i][0])+square(Vector3t[i][1])+(Vector3t[i][2]));
			if(value<min){
	}
}
