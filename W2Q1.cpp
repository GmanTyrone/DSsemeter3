#include <cstdio>

void allocArray(int ***p, int m, int n)
{
    int *bloque = new int[m*n];
    *p = new int* [m];
    for(int i=0;i<m;++i){
        (*p)[i]=&bloque[i*n];
    }
}


int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));
}
