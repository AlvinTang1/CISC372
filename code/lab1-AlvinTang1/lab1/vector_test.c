#include "types.h"
#include "utilities.h"
#include <stdio.h>
#define FLT_MAX  3.4028234664e+38
int	smallest(const	Vector3t*	pts,int	n);
int main(){
      int signed_N,result;
      unsigned int N;
      printf("Number of elements ===>  ");
      scanf("%d", &signed_N);
      N = signed_N;
      Vector3t points[N];
      printf("\n");
      for(int i=1; i<=N; i++){
      int tempx,tempy,tempz;
      printf("point %d; ", i);
      scanf("%d,%d,%d", &tempx,&tempy,&tempz);
      points[i-1].x = tempx;
      points[i-1].y = tempy;
      points[i-1].z = tempz;
      }
      result = smallest(points, N);
      printf("The point closest to the origin is %d,%d,%d", points[result].x,points[result].y,points[result].z);
      return 0;
      
      }
int	smallest(const Vector3t* pts, int n)
{
	float min,value;
	int small;
    min = FLT_MAX;
	for(int i=1;i<=n;i++)
	{
		value = sqrt(pow(pts[i-1].x,2)+pow(pts[i-1].y,2)+pow(pts[i-1].z,2));
			if(value<min){
				min = value;
				small = i-1;
			}
	}
	return small;
}
